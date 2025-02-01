#include <Windows.h>
#include "lvgl/lvgl.h"
#include<iostream>

#define HEADER_HEIGHT_CUS 48

#define BOX_COUNT 15  // Number of boxes diagonally
#define BOX_SIZE 50  // Size of each box
#define XRES 800
#define YRES 480

static void box_event_cb(lv_event_t* e) {
    lv_obj_t* obj = (lv_obj_t *)lv_event_get_target(e);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0x00FF00), 0);  // Change to green on touch
}

void button_event_handler(lv_event_t* e)
{
    printf("Button clicked!\n");
}

void lv_example_touchscreen_test(void) {
    lv_obj_t* scr = lv_scr_act();
    lv_obj_set_style_bg_color(scr, lv_color_black(), 0);

    lv_obj_t* label = lv_label_create(scr);
    lv_label_set_text(label, "TOUCH TEST ONGOING");
    lv_obj_set_style_text_color(label, lv_color_white(), 0);
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 50);

    int box_xres = XRES / BOX_COUNT;
    int box_yres = YRES / BOX_COUNT;
    for (int i = 0; i < BOX_COUNT; i++) {
        lv_obj_t* box = lv_obj_create(scr);
        lv_obj_set_size(box, box_xres, box_yres);
        lv_obj_set_style_bg_color(box, lv_color_hex(0x808080), 0);  // Grey
        lv_obj_align(box, LV_ALIGN_TOP_LEFT, i * box_xres, i * box_yres);
        lv_obj_add_event_cb(box, box_event_cb, LV_EVENT_PRESSED, NULL);
    }

    for (int i = 0; i < BOX_COUNT; i++) {
        lv_obj_t* box = lv_obj_create(scr);
        lv_obj_set_size(box, box_xres, box_yres);
        lv_obj_set_style_bg_color(box, lv_color_hex(0x808080), 0);  // Grey
        lv_obj_align(box, LV_ALIGN_TOP_RIGHT, -i * box_xres, i * box_yres);
        lv_obj_add_event_cb(box, box_event_cb, LV_EVENT_PRESSED, NULL);
    }

    lv_obj_t* btn = lv_btn_create(scr);
    lv_obj_align(btn, LV_ALIGN_BOTTOM_MID, 0, -90);
    lv_obj_add_event_cb(btn, button_event_handler, LV_EVENT_CLICKED, NULL);

    lv_obj_t* btn_label = lv_label_create(btn);
    lv_label_set_text(btn_label, "PASS");
    lv_obj_center(btn_label);
}


void start_factory_test_touch_f(void)
{
    lv_example_touchscreen_test();
}
