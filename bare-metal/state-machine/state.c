#include "state.h"

// запрещаем оптимизацию переменной
// так как она будет изменяться из вне
volatile state_t state = STATE_TIME;
