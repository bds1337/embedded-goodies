#include "drv_button.h"
#include <stdlib.h>

void drv_button_init(drv_button_t *btn)
{
    if (btn == NULL)
        return;
    btn->button = NULL;
    btn->timer  = NULL;
    btn->emit   = NULL;
    btn->old_state  = 0;
    btn->state      = 0;
}

void drv_button_destroy(drv_button_t *btn)
{
    if (btn == NULL)
        return;
    free(btn);
}

void drv_button_set_timer(drv_button_t *btn, struct timer_t* timer)
{
    btn->timer = timer;
}

void drv_button_set_button(drv_button_t *btn, struct button_t* button)
{
    btn->button = button;
}

void drv_button_set_emit(drv_button_t *btn, struct microwave_emmiter_t* emit)
{
    btn->emit = emit;
}

drv_button_t * drv_button_create(struct timer_t* time,
                                 struct button_t* btn,
                                 struct microwave_emmiter_t* emit) 
{
    drv_button_t* drv_btn = (drv_button_t*)malloc(sizeof(drv_button_t));
    if (drv_btn == NULL)
        return; 
    drv_button_init(drv_btn);
}

void drv_button_recv_event(drv_button_t *btn) 
{

}