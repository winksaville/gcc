/* { dg-do compile } */
/* { dg-options "-O2 -Wall -g" } */

void
__attribute__((interrupt))
fn (void *frame)
{
}

void (*fns[]) (void *) __attribute__((interrupt)) =
{
  fn,
};

/* { dg-final { scan-assembler-not "add(l|q)\[\\t \]*\\$\[0-9\]*,\[\\t \]*%\[re\]?sp" } } */
/* { dg-final { scan-assembler "iret" { target ia32 } } } */
/* { dg-final { scan-assembler "iretq" { target { ! ia32 } } } } */
