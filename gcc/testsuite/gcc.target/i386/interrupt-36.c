/* { dg-do compile } */
/* { dg-options "-O2" } */


extern void *a;
extern int b;

static inline
__attribute__ ((cold)) void
my_cold_memset (void *a, int b,int c)
{
  __builtin_memset (a,b,c);
}

__attribute__ ((interrupt))
void
foo (void *frame)
{
  if (a)
    my_cold_memset (a,b,40);
}

/* The IF conditional should be predicted as cold and my_cold_memset inlined
   for size expanding memset as rep; stosb.  */
/* { dg-final { scan-assembler "stosb" } } */
/* { dg-final { scan-assembler-times "cld" 1 } } */
