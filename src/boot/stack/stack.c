#include <stdint.h>
#include "stack.h"

//section .bss
uint8_t stack[STACK_SIZE_KB] __attribute__((section(".bss")));
