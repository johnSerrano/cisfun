#include <stdio.h>
/* 218922995834555169026 */

void fib(int *a1, int *a2, int *a3, int *b1, int *b2, int *b3);
void print_fib(int a1, int a2, int a3);

/* print the first 98 fibonacci numbers*/
int main() {
  int a1;
  int a2;
  int a3;
  int b1;
  int b2;
  int b3;
  int i = 0;
  a1=0;
  a2=0;
  a3=1;
  b1=0;
  b2=0;
  b3=2;
  for (i=0; i<98; i++) {
    fib(&a1,&a2,&a3,&b1,&b2,&b3);
  }
  printf("\n");
  return 0;
}

/* (a, b) = (b, a+b)*/

void fib(int *a1, int *a2, int *a3, int *b1, int *b2, int *b3) {
  int temp;
  print_fib(*a1,*a2,* a3);
  temp = *a3;
  *a3 = *b3;
  *b3 += temp;

  temp = *a2;
  *a2 = *b2;
  if (*b3 >= 1000000) {
    *b3 -= 1000000;
    *b2 += 1;
  }
  *b2 += temp;

  temp = *a1;
  *a1 = *b1;
  if (*b2 >= 1000000) {
    *b2 -= 1000000;
    *b1 += 1;
  }
  *b1 += temp;
}

void print_fib(int a1, int a2, int a3) {
  if (a3 != 1) {
    printf(", ");
  }
  if (a1 == 0) {
    if (a2 == 0) {
      printf("%d", a3);
    } else {
      printf("%d%.6d", a2, a3);
    }
  } else {
    printf("%d%.6d%.6d", a1, a2, a3);
  }
}
