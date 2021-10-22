// Пример программы машины состояния

#include <stdio.h>
//#include <unistd.h> //в Linux, для операции sleep
#include "state.h"

extern state_t state;

void fatal_error(void) 
{
    printf("panic!");
    for(;;);
}

void button_handler(void) 
{
    switch (state) 
    {
        case STATE_TIME:
          printf("change time to date\n");
          state = STATE_DATE;
          break;
        case STATE_DATE:
          printf("change date to time\n");
          state = STATE_TIME;
          break;
        default:
          fatal_error();
    }
}

int main(void) 
{
    printf("initialization complete \n");
    // init
    for(;;) 
    {
        switch (state) 
        {
        case STATE_TIME:
          printf("Time: 20:22\n");
          break;
        case STATE_DATE:
          printf("Date: 3 of september\n");
          break;
        default:
          fatal_error();
        }
        // эмулируем прерывание (нажатие на кнопку)
        //sleep(1);
        button_handler();
    }
    return 0;
}
