/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question07                */

#ifndef _QUESTION07_H_
#define _QUESTION07_H_

struct list {
  int           val;
  struct list  *next;
};

int circular_list_mem(struct list *l, int x);

#endif
