
#include <stdio.h>
#include <stdbool.h>

#include "version.h"

//! Intro message
/*!
 * Print the intro message
 */
void intro()
{
  printf("*** Millenium Lisp %s ***\n", gGIT_VERSION_SHORT);
  puts("Fun lisp implementation in C!");
  puts("Well ..., have fun!\n");
}

int main(int argc, char *argv[])
{
  char buffer[2048] = "\0";
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
