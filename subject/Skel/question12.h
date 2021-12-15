/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question12                */

#include <stdlib.h>
#include <unistd.h>

#ifndef _QUESTION12_H
#define _QUESTION12_H

struct image {
  int           white;
  struct image *upleft, *upright, *downleft, *downright;
};

int is_white(struct image *img);

#endif
