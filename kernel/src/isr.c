// /*
//  * isr.c - Interrupt Service Routines
//  * Author(s) - amrix, KapPetrov
//  */

// #include <isr.h>
// #include <idt.h>
// #include <console.h>
// #include <vga.h>
// #include <pic.h>
// #include <irq.h>

// #define NULL		0

// // Array to store interrupt handlers
// InterruptHandler interruptHandlers[256] = { NULL };

// const char *exceptionMsgs[] = {
//     "Division by zero",
//     "Debug",
//     "Non maskable interrupt",
//     "Breakpoint",
//     "Overflow",
//     "Invalid opcode",
//     "No coprocessor",
//     "Double fault",
//     "Coprocessor segment overrun",
//     "Bad TSS",
//     "Segment not present",
//     "Stack fault",
//     "General protection fault",
//     "Page fault",
//     "Unknown interrupt",
//     "Coprocessor fault",
//     "Alignment check",
//     "Machine check",
//     "Reserved"
// };

// void SetInterruptHandler(uint8_t interruptNumber, InterruptHandler handler)
// {
//     if (interruptNumber < 256)
//     {
//         interruptHandlers[interruptNumber] = handler;
//     }
// }

// void EnableInterrupt(uint8_t interruptNumber)
// {
//     if (interruptNumber < 8)
//     {
//         uint8_t mask = ~(1 << (interruptNumber % 8));
//         uint8_t *interruptMask = (uint8_t *)0x21;  // PIC1_DATA port address
//         *interruptMask &= mask;
//     }
// }

// void InstallPic()
// {
// 	PicInit();
// 	EnableInterrupt(IRQ1);
// }

// void InstallIsr(void)
// {
//     InstallPic();
//     SetInterruptHandler(IRQ1, IrqHandler);

//     PutStr("Installed ISRs\n");
// }

// void CFaultHandler(int interrupt)
// {
//     if (interrupt < 32) {

// 		Clear(1);

// 		PutISRExceptionStr("ISR Exception : ", 1);
// 		PutISRExceptionStr(exceptionMsgs[interrupt], 1);
//     }

//     while (1)
//         asm volatile("cli; hlt");
// }