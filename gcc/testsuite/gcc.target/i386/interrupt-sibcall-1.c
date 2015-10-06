/* { dg-do compile } */
/* { dg-options "-O3" } */

extern void foo (void *) __attribute__ ((interrupt));
extern void bar (void);

void foo (void *frame)
{
  bar ();
}
/* { dg-final { scan-assembler-not "jmp" } } */
/* { dg-final { scan-assembler "iret" { target ia32 } } } */
/* { dg-final { scan-assembler "iretq" { target { ! ia32 } } } } */
