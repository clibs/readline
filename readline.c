
//
// readline.c
//
// Copyright (c) 2014 Yorkie Neil <yorkiefixer@gmail.com>
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "readline.h"

readline_t * readline_new(char * buffer) {
  readline_t * rl = (readline_t*) malloc(sizeof(readline_t));
  size_t len = strlen(buffer);

  rl->cursor = 0;
  rl->line = 0;
  rl->buffer = (char*) malloc(len);
  memset(rl->buffer, 0, len);
  memcpy(rl->buffer, buffer, len);
  return rl;
}

char * readline_next(readline_t * rl) {
  size_t cur = rl->cursor;
  size_t len;
  char * ret = NULL;

  while (rl->buffer[cur++] != '\n' && cur < strlen(rl->buffer));
  len = cur - rl->cursor - 1;
  ret = (char*) malloc(len);

  if (ret == NULL || len == 0) {
    free(ret);
    return NULL;
  }
  
  memset(ret, 0, len);
  memcpy(ret, rl->buffer+rl->cursor, len);
  rl->cursor = cur;
  rl->line += 1;
  return ret;
}

void readline_free(readline_t * rl) {
  rl->cursor = 0;
  rl->line = 0;
  free(rl);
}