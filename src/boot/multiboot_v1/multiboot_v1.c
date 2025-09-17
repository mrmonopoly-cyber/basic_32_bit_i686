#include <stdint.h>
#include "../stack/stack.h"

#define V_ALIGN (1<<0)                    /* align loaded modules on page boundaries */
#define V_MEMINFO  (1<<1)                 /* provide memory map */
#define V_FLAGS    (V_ALIGN | V_MEMINFO)      /* this is the Multiboot 'flag' field */
#define V_MAGIC    0x1BADB002             /* 'magic number' lets bootloader find the header */
#define V_CHECKSUM (-(V_MAGIC + V_FLAGS))     /* checksum of above, to prove we are multiboot */

//section .multiboot
struct __attribute__((packed, aligned(16))) multiboot_header{
  uint32_t MAGIC;
  uint32_t FLAGS;
  uint32_t CHECKSUM;
};

struct multiboot_header mb_header __attribute__((section(".multiboot")))= {
  .MAGIC = V_MAGIC,
  .FLAGS = V_FLAGS,
  .CHECKSUM = V_CHECKSUM,
};

__attribute__((naked, section(".text")));
void _start(void)
{
  asm volatile ("movl %0, %%esp"
       :
       :"r"(stack + sizeof(stack))
       :);

  asm volatile(
      "call kernel_main\n"
      "cli\n"
      "1: hlt\n"
      "jmp 1b");
}
