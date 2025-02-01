#ifndef EEZ_LVGL_UI_EVENTS_H
#define EEZ_LVGL_UI_EVENTS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void action_button_1_pressed(lv_event_t * e);
extern void action_button_2_pressed(lv_event_t * e);
extern void action_slider_1_value_changed(lv_event_t * e);
extern void action_textarea_1_focused(lv_event_t * e);
extern void action_textarea_1_defocused(lv_event_t * e);
extern void action_switch_1_value_changed(lv_event_t * e);


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_EVENTS_H*/