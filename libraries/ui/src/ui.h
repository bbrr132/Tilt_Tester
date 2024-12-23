// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: Tilt_Tester

#ifndef _TILT_TESTER_UI_H
#define _TILT_TESTER_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"

// SCREEN: ui_Screen1
void ui_Screen1_screen_init(void);
extern lv_obj_t * ui_Screen1;
extern lv_obj_t * ui_TopPanel;
extern lv_obj_t * ui_TopLabel;
extern lv_obj_t * ui_BottomPanel;
extern lv_obj_t * ui_ZeroButton;
void ui_event_ZeroButton(lv_event_t * e);
extern lv_obj_t * ui_ZeroStepperLabel;
extern lv_obj_t * ui_MoveToAngleButton;
void ui_event_MoveToAngleButton(lv_event_t * e);
extern lv_obj_t * ui_MoveToAngleLabel;
extern lv_obj_t * ui_MoveByAngleButton;
void ui_event_MoveByAngleButton(lv_event_t * e);
extern lv_obj_t * ui_MoveByLabel;
extern lv_obj_t * ui_InputValuePanel;
extern lv_obj_t * ui_MoveToAngleLabel1;
void ui_event_MoveToAngleTextArea(lv_event_t * e);
extern lv_obj_t * ui_MoveToAngleTextArea;
extern lv_obj_t * ui_MoveByAngleLabel;
void ui_event_MoveByAngleTextArea(lv_event_t * e);
extern lv_obj_t * ui_MoveByAngleTextArea;
extern lv_obj_t * ui_VelocityLabel;
void ui_event_VelocityTextArea(lv_event_t * e);
extern lv_obj_t * ui_VelocityTextArea;
extern lv_obj_t * ui_MotorAnglePanel;
extern lv_obj_t * ui_Arc1;
extern lv_obj_t * ui_Label6;
void ui_event_Keyboard1(lv_event_t * e);
extern lv_obj_t * ui_Keyboard1;
// CUSTOM VARIABLES

// EVENTS

extern lv_obj_t * ui____initial_actions0;

// UI INIT
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif