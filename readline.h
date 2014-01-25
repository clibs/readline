
//
// readline.h
//
// Copyright (c) 2014 Yorkie Neil <yorkiefixer@gmail.com>
//

#ifndef READLINE__H_
#define READLINE__H_

/*
 * Readline struct
 */

typedef struct readline_s {
  char * buffer;
  size_t cursor;
  size_t line;
} readline_t;


/*
 * create a new readline struct
 */

readline_t * readline_new(char * buffer);

/*
 * next cursor
 */

char * readline_next(readline_t * rl);

/*
 * free the object
 */

void readline_free(readline_t * rl);


#endif
