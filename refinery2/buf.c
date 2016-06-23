#include <unistd.h>
#include <stdio.h>
void print_buffer(char *b, int size);
int print_char(char);
void print_in_base(int, int, int);

int main(void)
{
   char buffer[] = "This is a string!\0And this is the rest of the #buffer :)\1\2\3\4\5\6\7#cisfun\n\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x21\x34\x56#pointersarefun #infernumisfun\n";

   printf("%s\n", buffer);
   printf("---------------------------------\n");
   print_buffer(buffer, sizeof(buffer));
   return (0);
}

/* prints a character */
int print_char(char c)
{
   return (write(1, &c, 1));
}

/* prints a buffer represented in hex and ascii*/
void print_buffer(__attribute__((unused)) char *b, int size) {
  int iters = size / 10;
  int i;
  int j;
  char printme;
  if (size % 10 != 0) iters++;
  for (i = 0; i<iters; i++) {
    print_in_base((i+1) * 10, 16, 8);
    print_char(':');
    print_char(' ');
    for (j = 0; j < 5; j++) {
      if (i*10 + j*2 >= size){
        print_char(' ');
        print_char(' ');
      }
      else print_in_base(b[i*10 + j*2], 16, 2);
      if (i*10 + (j*2+1) >= size){
        print_char(' ');
        print_char(' ');
      }
      else print_in_base(b[i*10 + j*2 + 1], 16, 2);
      print_char(' ');
    }
    for (j=0 ; j<10 ; j++) {
      if (i*10 + j >= size) continue;
      printme = b[i*10 + j];
      (printme > 31) ? print_char(printme) : print_char('.');
    }
    print_char('\n');
  }
}

/* prints a number in the specified base (up to 37)*/
void print_in_base(int num, int base, int pad) {
  int exponent = 1;
  int num_c = num;
  int divisor = 1;
  char t_p;
  while (num_c > base-1) {
    num_c /= base;
    exponent++;
    divisor *= base;
  }
  for (t_p=0 ; t_p<(pad-exponent) ; t_p++) print_char('0');
  if (num == 0) {
    print_char('0');
    return;
  }
  while (divisor > 0) {
    exponent = num/divisor;
    num = num - exponent*divisor;
    if (exponent > 9)  {
      t_p = 'a' + exponent-10;
    } else t_p = '0' + exponent;
    divisor /= base;
    print_char(t_p);
  }
}
