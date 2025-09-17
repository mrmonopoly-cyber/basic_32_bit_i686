#include "../../kernel/kernel.h"

#include <stdint.h>

#define STACK_SIZE_KB 16384

//section .bss
uint8_t stack[STACK_SIZE_KB] __attribute__((section(".bss")));

void _start(void)__attribute__((naked));
void _start(void)
{
  asm volatile ("movl %0, %%esp"
       :
       :"r"(stack + sizeof(stack))
       :);

  _kmain();

  asm volatile(
      "cli\n"
      "1: hlt\n"
      "jmp 1b");
}
