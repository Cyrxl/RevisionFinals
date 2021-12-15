/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question01                */

#define QNUM 1
#define QOPT "seed size"
#define QNOPT 2

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "base_test.h"
#include "question01.h"

void fixed_test(size_t len) {
  printf("Fixed tests:\n");
  for (unsigned long i = 0; i < len; ++i) {
    unsigned long       n = (unsigned long)1 << i;
    printf("  msb(%19lu) = %2lu (expected %lu)\n",
           n, msb(n), i + 1);
  }
}

void random_test(size_t len) {
  printf("Random tests:\n");
  for (unsigned long i = 0; i < len; ++i) {
    unsigned long               var, n;
    var = random() % 64;
    n = random();
    n = (n << 31) + random();
    n = n % ((unsigned long)1 << var);
    printf("  msb(%19lu) = %2lu\n",
           n, msb(n));
  }
}


int main(int argc,char *argv[])
{
  size_t        size;

  help_asked(argc,argv,QNUM,QOPT,QNOPT);

  if (argc <= QNOPT)
    {
      fprintf(stderr, "Parametres insuffisants.\n");
      usage(NULL,QNUM,QOPT);
    }
  else
    {
      seedInit(argv);
      size = getSize(argv);
      fixed_test(size);
      random_test(size);
    }
  exit(0);
}
