#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 480);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_btn_create(parent_obj);
            lv_obj_set_pos(obj, 52, 173);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_button_1_pressed, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // button_1
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.button_1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Increment");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // button_2
            lv_obj_t *obj = lv_btn_create(parent_obj);
            objects.button_2 = obj;
            lv_obj_set_pos(obj, 174, 173);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_button_2_pressed, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_label_set_text(obj, "Decrement");
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                }
            }
        }
        {
            // label_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_1 = obj;
            lv_obj_set_pos(obj, 52, 97);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Label");
        }
        {
            // textarea_1
            lv_obj_t *obj = lv_textarea_create(parent_obj);
            objects.textarea_1 = obj;
            lv_obj_set_pos(obj, 124, 87);
            lv_obj_set_size(obj, 150, 36);
            lv_textarea_set_max_length(obj, 128);
            lv_textarea_set_one_line(obj, true);
            lv_textarea_set_password_mode(obj, false);
            lv_obj_add_event_cb(obj, action_textarea_1_defocused, LV_EVENT_DEFOCUSED, (void *)0);
            lv_obj_add_event_cb(obj, action_textarea_1_focused, LV_EVENT_FOCUSED, (void *)0);
        }
        {
            // label_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.label_2 = obj;
            lv_obj_set_pos(obj, 10, 447);
            lv_obj_set_size(obj, 300, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "");
        }
        {
            // slider_1
            lv_obj_t *obj = lv_slider_create(parent_obj);
            objects.slider_1 = obj;
            lv_obj_set_pos(obj, 52, 266);
            lv_obj_set_size(obj, 222, 10);
            lv_slider_set_value(obj, 25, LV_ANIM_OFF);
            lv_obj_add_event_cb(obj, action_slider_1_value_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
        }
        {
            // switch_1
            lv_obj_t *obj = lv_switch_create(parent_obj);
            objects.switch_1 = obj;
            lv_obj_set_pos(obj, 52, 39);
            lv_obj_set_size(obj, 50, 25);
            lv_obj_add_event_cb(obj, action_switch_1_value_changed, LV_EVENT_VALUE_CHANGED, (void *)0);
        }
        {
            // keyboard_1
            lv_obj_t *obj = lv_keyboard_create(parent_obj);
            objects.keyboard_1 = obj;
            lv_obj_set_pos(obj, 10, 305);
            lv_obj_set_size(obj, 300, 120);
            lv_keyboard_set_mode(obj, LV_KEYBOARD_MODE_NUMBER);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
}

void tick_screen_main() {
}


void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}

typedef void (*tick_screen_func_t)();

tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};

void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
