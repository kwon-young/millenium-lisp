
#include <stdio.h>
#include <stdbool.h>

void intro()
{
  puts("*** Millenium Lisp ***");
  puts("Fun lisp implementation in C!");
  puts("Well ..., have fun!");
}

int main(int argc, char *argv[])
{
  char buffer[256] = "\0";
  bool cont = true;

  intro();

  while(cont)
  {
    fputs("mlisp@>", stdout);
    fgets(buffer, 256, stdin);
    fputs(buffer, stdout);
  }
  return 0;
}
