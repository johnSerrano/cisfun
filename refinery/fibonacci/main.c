#include <stdio.h>

void print_numbers(int a, int b, int c);

/* print first 98 fibonacci numbers */
int main() {
  int a2 = 0;
  int a3 = 0;
  int a4 = 1;
  int b2 = 0;
  int b3 = 0;
  int b4 = 1;
  int count = 0;
  int carry = 0;
  int tmp2 = 0;
  printf("%d", 1);
  while (count < 97) {
    carry = ((a4 + b4) - ((a4 + b4) % 1000000000)) / 1000000000;
    a4 = (a4 + b4) - (carry * 1000000000);
    b4 = (a4 + (carry * 1000000000) - b4);
    tmp2 = ((a3 + b3 + carry) - ((a3 + b3) % 1000000000)) / 1000000000;
    a3 = (a3 + b3 + carry) - (tmp2 * 1000000000);
    b3 = (a3 + (tmp2 * 1000000000) - b3 - carry);
    carry = ((a2 + b2 + tmp2) - ((a2 + b2) % 1000000000)) / 1000000000;
    a2 = (a2 + b2 + tmp2) - (carry * 1000000000);
    b2 = (a2 + (carry * 1000000000) - b2 - tmp2);
    print_numbers(a2, a3, a4);
    count++;
  }
  return 0;
}

/* prints one number from three ints*/
void print_numbers(int a, int b, int c) {
  if (a != 0) printf(", %d%d%d", a, b, c);
  else if (b != 0) printf(", %d%d", b, c);
  else printf(", %d", c);
  if (a == 218 && b == 922995834 && c == 555169026) printf("\n");
}
