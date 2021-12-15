/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question01                */

# include "question01.h"

unsigned long msb(unsigned long n) {
  unsigned long res = 0;
  while (n > 0)
  {
      n = n >> 1;
      res++;
  }
  return res;
}
