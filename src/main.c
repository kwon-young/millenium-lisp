
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <editline.h>

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
  bool cont = true;

  intro();

  while(cont)
  {
    char* input = readline("mlisp@>");
    add_history(input);
    printf("%s\n", input);
    free(input);
  }
  return 0;
}
