/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question10                */

#ifndef _QUESTION10_H_
#define _QUESTION10_H_

struct tree {
  int           key;
  struct tree  *left, *right;
};

int height(struct tree *t);

#endif
