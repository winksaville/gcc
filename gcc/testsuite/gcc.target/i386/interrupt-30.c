/* { dg-do compile { target ia32 } } */
/* { dg-options "-O2 -miamcu -maccumulate-outgoing-args" } */

struct interrupt_frame;

void (*callback[1])(unsigned int id, unsigned int len);
unsigned int remaining;

void
__attribute__((no_caller_saved_registers))
handler(int uart)
{
  while (1) {
    if (remaining) {
      callback[uart](0, 0);
      break;
    }
  }
}

int uart;

void
__attribute__((interrupt))
my_isr(struct interrupt_frame *frame)
{
  handler(uart);
}
