// Пример программы указатели на функции

#include <stdio.h>
//#include <unistd.h> //в Linux, для операции sleep
#include "state.h"

void fatal_error(void) 
{
    printf("panic!");
    for(;;);
}

void button_handler(void) 
{
}

int main(void) 
{
    printf("initialization complete \n");
    // init
    for(;;) 
    {
        state = (state_func_ptr_t)(*state)();
        // эмулируем прерывание (нажатие на кнопку)
        //sleep(1);
        button_handler();
    }
    return 0;
}
