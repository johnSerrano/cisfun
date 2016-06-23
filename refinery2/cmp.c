#include <stdio.h>

int shell_comp(char *s1, char *s2);


int main(void)
{
  int r;

  r = shell_comp("main.c", "*.c");
  printf("%d\n", r);
  r = shell_comp("main.c", "m*a*i*n*.*c*");
  printf("%d\n", r);
  r = shell_comp("main.c", "main.c");
  printf("%d\n", r);
  r = shell_comp("main.c", "m*c");
  printf("%d\n", r);
  r = shell_comp("main.c", "ma********************************c");
  printf("%d\n", r);
  r = shell_comp("main.c", "*");
  printf("%d\n", r);
  r = shell_comp("main.c", "***");
  printf("%d\n", r);
  r = shell_comp("main.c", "m.*c");
  printf("%d\n", r);
  r = shell_comp("main.c", "**.*c");
  printf("%d\n", r);
  r = shell_comp("main-main.c", "ma*in.c");
  printf("%d\n", r);
  r = shell_comp("main", "main*d");
  printf("%d\n", r);
  r = shell_comp("abc", "*b");
  printf("%d\n", r);
  return (0);
}

int shell_comp(char *s1, char *s2) {
  if (*s1 == 0 && *s2 == 0) return 1;
  if (*s2 == '*' && *(s2 + 1) == '*') return shell_comp(s1, (s2+1));
  if (*s2 == '*' && *(s2 + 1) == 0) return 1;
  if (*s2 == '*' && *s1 == 0) return 0;
  if (*s2 == '*') return (shell_comp((s1 +1), s2) || shell_comp(s1, (s2+1)));
  if (*s2 != *s1) return 0;
  return shell_comp((s1+1), (s2+1));
}
