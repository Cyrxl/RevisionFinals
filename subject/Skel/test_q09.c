/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question09                */

#define QNUM 9
#define QOPT "seed size"
#define QNOPT 1

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "base_test.h"
#include "question09.h"

static inline
char* getcmp(int c) {
  if (c == 0)
    return "==";
  if (c < 0)
    return "<";
  return ">";
}

void fixed_test() {
  char         s1[] = "aaaaaa";
  char         s2[] = "aaaaab";
  printf("Fixed Tests:\n");
  printf("  s1: \"%s\"\n", s1);
  printf("  s2: \"%s\"\n", s2);
  int           r;
  r = my_strcmp(s1,s1);
  printf("my_strcmp(s1,s1) = s1 %s s1 \t(%s)\n", getcmp(r), check(r == 0));
  r = my_strcmp(s1,s2);
  printf("my_strcmp(s1,s2) = s1 %s s2 \t(%s)\n", getcmp(r), check(r < 0));
  r = my_strcmp(s2,s1);
  printf("my_strcmp(s2,s1) = s2 %s s1 \t(%s)\n", getcmp(r), check(r > 0));
}

void random_test(size_t len) {
  char        *s1;
  char        *s2;
  printf("\nRandom Tests:\n");
  s1 = calloc(len + 1, 1);
  s2 = calloc(len + 1, 1);
  randstr(s1, len);
  randstr(s2, len);
  printf("  s1: \"%s\"\n", s1);
  printf("  s2: \"%s\"\n", s2);
  int           r;
  r = my_strcmp(s1,s2);
  printf("my_strcmp(s1,s2) = s1 %s s2\n", getcmp(r));
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
      fixed_test();
      random_test(size);
    }
  exit(0);
}
