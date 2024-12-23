// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: Tilt_Tester

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
lv_obj_t * ui_Screen1;
lv_obj_t * ui_TopPanel;
lv_obj_t * ui_TopLabel;
lv_obj_t * ui_BottomPanel;
lv_obj_t * ui_ZeroButton;
lv_obj_t * ui_ZeroStepperLabel;
lv_obj_t * ui_MoveToAngleButton;
lv_obj_t * ui_MoveToAngleLabel;
lv_obj_t * ui_MoveByAngleButton;
lv_obj_t * ui_MoveByLabel;
lv_obj_t * ui_InputValuePanel;
lv_obj_t * ui_MoveToAngleLabel1;
void ui_event_MoveToAngleTextArea(lv_event_t * e);
lv_obj_t * ui_MoveToAngleTextArea;
lv_obj_t * ui_MoveByAngleLabel;
void ui_event_MoveByAngleTextArea(lv_event_t * e);
lv_obj_t * ui_MoveByAngleTextArea;
lv_obj_t * ui_VelocityLabel;
void ui_event_VelocityTextArea(lv_event_t * e);
lv_obj_t * ui_VelocityTextArea;
lv_obj_t * ui_MotorAnglePanel;
lv_obj_t * ui_Arc1;
lv_obj_t * ui_Label6;
void ui_event_Keyboard1(lv_event_t * e);
lv_obj_t * ui_Keyboard1;
// CUSTOM VARIABLES

// EVENTS
lv_obj_t * ui____initial_actions0;

// IMAGES AND IMAGE SETS

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_MoveToAngleTextArea(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_FOCUSED) {
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
    if(event_code == LV_EVENT_FOCUSED) {
        _ui_keyboard_set_target(ui_Keyboard1,  ui_MoveToAngleTextArea);
    }
    if(event_code == LV_EVENT_FOCUSED) {
        lv_obj_add_flag(ui_MoveByAngleLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_MoveByAngleTextArea, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_VelocityLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_VelocityTextArea, LV_OBJ_FLAG_HIDDEN);
	lv_obj_scroll_to_y(ui_InputValuePanel, 0, LV_ANIM_OFF);
    }
}

void ui_event_MoveByAngleTextArea(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_FOCUSED) {
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
    if(event_code == LV_EVENT_FOCUSED) {
        _ui_keyboard_set_target(ui_Keyboard1,  ui_MoveByAngleTextArea);
    }
    if(event_code == LV_EVENT_FOCUSED) {
        lv_obj_add_flag(ui_MoveToAngleLabel1, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_MoveToAngleTextArea, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_VelocityLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_VelocityTextArea, LV_OBJ_FLAG_HIDDEN);
	lv_obj_scroll_to_y(ui_InputValuePanel, 0, LV_ANIM_OFF);
    }
}

void ui_event_VelocityTextArea(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_FOCUSED) {
        _ui_keyboard_set_target(ui_Keyboard1,  ui_VelocityTextArea);
    }
    if(event_code == LV_EVENT_FOCUSED) {
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
    }
    if(event_code == LV_EVENT_FOCUSED) {
        lv_obj_add_flag(ui_MoveToAngleLabel1, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_MoveToAngleTextArea, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_MoveByAngleLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_MoveByAngleTextArea, LV_OBJ_FLAG_HIDDEN);
	lv_obj_scroll_to_y(ui_InputValuePanel, 0, LV_ANIM_OFF);
    }
}

void ui_event_Keyboard1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_READY) {
        _ui_flag_modify(ui_Keyboard1, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
	lv_obj_clear_flag(ui_VelocityLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_VelocityTextArea, LV_OBJ_FLAG_HIDDEN);
	lv_obj_clear_flag(ui_MoveToAngleLabel1, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_MoveToAngleTextArea, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_MoveByAngleLabel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_MoveByAngleTextArea, LV_OBJ_FLAG_HIDDEN);
        KeyboardDone(e);
    }
}

void ui_event_ZeroButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        ZeroButton(e);
    }
}
void ui_event_MoveToAngleButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        MoveToAngleButton(e);
    }
}
void ui_event_MoveByAngleButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);

    if(event_code == LV_EVENT_CLICKED) {
        MoveByAngleButton(e);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    lv_disp_load_scr(ui_Screen1);
}