/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question06                */

#ifndef _QUESTION06_H_
#define _QUESTION06_H_

struct list {
  int           val;
  struct list  *next;
};

void insert(struct list *l, int x);

#endif
