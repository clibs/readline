
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "readline.h"

#define test_start() \
  printf("\n================\n")  \


void test_readline_simple() {

  test_start();
  char * buf = "" \
    "c++\n"
    "lua\n";

  readline_t * rl = readline_new(buf);
  char * line = NULL;
  size_t count = 0;

  while ((line = (readline_next(rl))) != NULL) {
    count++;
    printf("line: %s\n", line);
  }
  assert(count == 2);
}

void test_readline_empty_line() {
  test_start();
  char * buf = "" \
    "c++\n"
    "\n"
    "javascript";

  readline_t * rl = readline_new(buf);
  char * line = NULL;
  size_t count = 0;

  while ((line = (readline_next(rl))) != NULL) {
    count++;
    printf("line: %s\n", line);
  }
}

void test_readline_last_line() {

  test_start();
  char * buf = "" \
    "c++\n"
    "lua\n"
    "javascript";

  readline_t * rl = readline_new(buf);
  char * line = NULL;
  size_t count = 0;

  while ((line = (readline_next(rl))) != NULL) {
    count++;
    printf("line: %s\n", line);
  }
  assert(count == 3);
}

void test_readline_last_empty_line() {

  test_start();
  char * buf = "" \
    "c++\n"
    "lua\n"
    "";

  readline_t * rl = readline_new(buf);
  char * line = NULL;
  size_t count = 0;

  while ((line = (readline_next(rl))) != NULL) {
    count++;
    printf("line: %s\n", line);
  }
  assert(count == 2);
}


int main() {

  test_readline_simple();
  test_readline_empty_line();
  test_readline_last_line();
  test_readline_last_empty_line();
  return 0;
}