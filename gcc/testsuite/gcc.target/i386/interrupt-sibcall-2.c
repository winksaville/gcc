/* { dg-do compile } */
/* { dg-options "-O3 -mno-sse -mpreferred-stack-boundary=3" { target { ! { ia32 } } } } */
/* { dg-options "-O3 -mpreferred-stack-boundary=2" { target { ia32 } } } */

extern void foo (void *) __attribute__ ((interrupt));
extern void bar (void) __attribute__ ((no_caller_saved_registers));

void foo (void *frame)
{
  bar ();
}
/* { dg-final { scan-assembler-not "jmp" } } */
/* { dg-final { scan-assembler "iret" { target ia32 } } } */
/* { dg-final { scan-assembler "iretq" { target { ! ia32 } } } } */
