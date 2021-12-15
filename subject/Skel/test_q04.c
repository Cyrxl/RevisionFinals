/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question04                */

#define QNUM 4
#define QOPT "seed size"
#define QNOPT 2

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "base_test.h"
#include "question04.h"

void print_tab(int tab[], size_t len) {
  printf("|");
  for (int *cur = tab; cur != tab + len; ++cur)
    printf(" %d |", *cur);
  printf("\n");
}

void test_search(int tab[], size_t len, int x) {
  int          *r;
  r = binsearch(tab, tab + len, x);
  if (r == NULL) {
    printf("  binsearch(tab, tab+len, %d) -> Not found\n", x);
  } else {
    printf("  binsearch(tab, tab+len, %d) -> found (%d)\n", x, *r);
  }
}

void fixed_test(size_t len) {
  printf("Fixed Tests:\n");
  int          *tab;
  tab = malloc(len * sizeof (int));
  for (size_t i = 0; i < len; ++i) {
    tab[i] = i;
  }
  printf("tab[] = \n  ");
  print_tab(tab, len);
  test_search(tab, len, 0);
  test_search(tab, len, len - 1);
  test_search(tab, len, len / 2);
  test_search(tab, len, len);
}

void random_test(size_t len) {
  printf("Random Tests:\n");
  int          *tab, last = -len;
  tab = malloc(len * sizeof (int));
  for (size_t i = 0; i < len; ++i) {
    last += 1 + random() % (len / 2);
    tab[i] = last;
  }
  printf("tab[] = \n  ");
  print_tab(tab, len);
  for (size_t i = 0; i < len; ++i) {
    test_search(tab, len, (random() % (3 * last)) - last);
  }
}

int main(int argc,char *argv[]) {
  size_t        size;

  help_asked(argc,argv,QNUM,QOPT,QNOPT);

  if (argc <= QNOPT) {
    fprintf(stderr, "Parametres insuffisants.\n");
    usage(NULL,QNUM,QOPT);
  } else {
    seedInit(argv);
    size = getSize(argv);
    fixed_test(size);
    random_test(size);
  }
  exit(0);
}
