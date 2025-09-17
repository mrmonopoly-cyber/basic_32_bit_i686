#ifndef __K_MAIN__
#define __K_MAIN__

void __kmain(void);

#define _kmain() asm volatile ("call __kmain") 


#endif // !__K_MAIN__
