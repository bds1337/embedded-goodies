#ifndef DRV_BUTTON_H
#define DRV_BUTTON_H

#define DEBOUCE_TIME 100

struct button_t;
struct microwave_emmiter_t;
struct timer_t;

typedef struct drv_button {
    char state;
    char old_state;
    struct button_t * button;
    struct microwave_emmiter_t* emit;
    struct timer_t * timer;
} drv_button_t;

void drv_button_init(drv_button_t *btn);
void drv_button_destroy(drv_button_t *btn);
void drv_button_set_timer(drv_button_t *btn, struct timer_t* timer);
void drv_button_set_button(drv_button_t *btn, struct button_t* button);
void drv_button_set_emit(drv_button_t *btn, struct microwave_emmiter_t* emit);

drv_button_t * drv_button_create(struct timer_t* timer,
                                 struct button_t* btn,
                                 struct microwave_emmiter_t* emit);

void drv_button_recv_event(drv_button_t *btn);

#endif