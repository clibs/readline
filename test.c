
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readline.h"

void test_readline() {

  char * buf = "" \
    "c++\n"
    "lua\n";

  readline_t * rl = readline_new(buf);
  char * line = NULL;

  do {
    line = readline_next(rl);
    printf("line: %s\n", line);

  } while (line != NULL);
}

int main() {

  test_readline();
  return 0;
}