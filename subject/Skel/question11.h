/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question11                */

#include <stdlib.h>
#include <unistd.h>

#ifndef _QUESTION11_H
#define _QUESTION11_H

struct tree {
  int           key;
  struct tree  *left, *right;
};

size_t prefix_list(struct tree *t, int keys[]);

#endif
