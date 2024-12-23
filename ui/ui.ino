#include <lvgl.h>
#include <TFT_eSPI.h>
#include <ui.h>
#include <TFT_Touch.h>
#include "Stepper.h"
#include "uiFunctions.h"
/*Don't forget to set Sketchbook location in File/Preferences to the path of your UI project (the parent foder of this INO file)*/


// These are the pins used to interface between the 2046 touch controller and Arduino Pro
#define DOUT 39  /* Data out pin (T_DO) of touch screen */
#define DIN  32  /* Data in pin (T_DIN) of touch screen */
#define DCS  33  /* Chip select pin (T_CS) of touch screen */
#define DCLK 25  /* Clock pin (T_CLK) of touch screen */

TFT_Touch touch = TFT_Touch(DCS, DCLK, DIN, DOUT);

/*Change to your screen resolution*/
static const uint16_t screenWidth  = 320;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[ screenWidth * screenHeight / 10 ];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

//For Stepper Motor
TaskHandle_t StepperController;

portMUX_TYPE mutex = portMUX_INITIALIZER_UNLOCKED;

void runStepperController(void *pvParameters)
{
  Serial.println("Starting Core 0, Setting Up Motor");
  setupStepperMotor();
  for (;;)
  {
    getTotalAngle();
    zeroMotor();
    moveStepperMotor();
    if (saveAngle) {
      saveAngle = false;
      prefHelper.storeSteps(step);
      prefHelper.storeRotations(rotations);
    }
    vTaskDelay(10);
  }
}
void startDualCore()
{
  xTaskCreatePinnedToCore(
    runStepperController,
    "Stepper Motor",
    10000,
    NULL,
    0,
    &StepperController,
    0);
  xTaskCreatePinnedToCore(guiTask, "GUI Task", 8192, NULL, 1, NULL, 1);
}

//For Serial Debugging
#if LV_USE_LOG != 0
/* Serial debugging */
void my_print(const char * buf)
{
  Serial.printf(buf);
  Serial.flush();
}
#endif

/* Display flushing */
void my_disp_flush( lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p )
{
  uint32_t w = ( area->x2 - area->x1 + 1 );
  uint32_t h = ( area->y2 - area->y1 + 1 );

  tft.startWrite();
  tft.setAddrWindow( area->x1, area->y1, w, h );
  tft.pushColors( ( uint16_t * )&color_p->full, w * h, true );
  tft.endWrite();

  lv_disp_flush_ready( disp );
}

void touch_calibrate()//屏幕校准
{
  uint16_t calData[5];
  uint8_t calDataOK = 0;

  //校准
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(20, 0);
  tft.setTextFont(2);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  tft.println("按指示触摸角落");

  tft.setTextFont(1);
  tft.println();

  tft.calibrateTouch(calData, TFT_MAGENTA, TFT_BLACK, 15);

  Serial.println(); Serial.println();
  Serial.println("//在setup()中使用此校准代码:");
  Serial.print("uint16_t calData[5] = ");
  Serial.print("{ ");

  for (uint8_t i = 0; i < 5; i++)
  {
    Serial.print(calData[i]);
    if (i < 4) Serial.print(", ");
  }

  Serial.println(" };");
  Serial.print("  tft.setTouch(calData);");
  Serial.println(); Serial.println();

  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.println("XZ OK!");
  tft.println("Calibration code sent to Serial port.");

}

/*Read the touchpad*/
void my_touchpad_read( lv_indev_drv_t * indev_driver, lv_indev_data_t * data )
{
  uint16_t touchX, touchY;

  bool touched = touch.Pressed();//tft.getTouch( &touchX, &touchY, 600 );

  if ( !touched )
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    touchX = touch.X();
    touchY = touch.Y();

    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;
  }
}

void setup()
{
  Serial.begin( 115200 ); /* prepare for possible serial debug */
  startDualCore();
}

void guiTask(void *pvParameters) {
  String LVGL_Arduino = "Hello Arduino! ";
  LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

  Serial.println( LVGL_Arduino );
  Serial.println( "I am LVGL_Arduino" );

  lv_init();

#if LV_USE_LOG != 0
  lv_log_register_print_cb( my_print ); /* register print function for debugging */
#endif

  tft.init();          /* TFT init */
  tft.setRotation( 1 ); /* Landscape orientation, flipped */
  touch.setCal(526, 3443, 750, 3377, 320, 240, 1);
  lv_disp_draw_buf_init( &draw_buf, buf, NULL, screenWidth * screenHeight / 10 );

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init( &disp_drv );
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register( &disp_drv );

  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init( &indev_drv );
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register( &indev_drv );


  ui_init();
  uiReady = true;
  portENTER_CRITICAL(&mutex);
  step = prefHelper.getSteps();
  rotations = prefHelper.getRotations();
  moveByAngle = prefHelper.getMoveByAngle();
  moveToAngleValue = prefHelper.getMoveToAngleValue();
  motorVelocity = prefHelper.getMotorVelocity();
  portEXIT_CRITICAL(&mutex);
  Serial.println(angle);
  lv_arc_set_value(ui_Arc1, (int16_t)angle);
  lv_label_set_text(ui_Label6, String(angle).c_str());
  lv_textarea_set_text(ui_MoveByAngleTextArea , String(moveByAngle).c_str());
  lv_textarea_set_text(ui_MoveToAngleTextArea  , String(moveToAngleValue).c_str());
  lv_textarea_set_text(ui_VelocityTextArea , String(motorVelocity).c_str());
  setMotorVelocity();
  for (;;) {
    lv_arc_set_value(ui_Arc1, (int16_t)angle);
    lv_label_set_text(ui_Label6, String(angle).c_str());
    lv_timer_handler();
    vTaskDelay(pdMS_TO_TICKS(5));
  }
}


void loop()
{
  //Serial.println(angle);
  //lv_arc_set_value(ui_Arc1, (int16_t)angle);
  //lv_label_set_text(ui_Label6, String(angle).c_str());

  //lv_timer_handler(); /* let the GUI do its work */
  //delay(5);
}
