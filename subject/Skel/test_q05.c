/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question05                */

#define QNUM 5
#define QOPT "seed size"
#define QNOPT 2

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "base_test.h"
#include "question05.h"

void print_tab(int tab[], size_t len) {
  printf("|");
  for (int *cur = tab; cur != tab + len; ++cur)
    printf(" %d |", *cur);
  printf("\n");
}

int is_sorted(int *left, int *right) {
  for (int *cur = left; cur < right - 1; ++cur) {
    if (*cur > *(cur+1)) return 0;
  }
  return 1;
}

void run(int tab[], size_t len) {
  printf("tab[] = \n  ");
  print_tab(tab, len);
  printf("After sort:\n  ");
  quick_sort(tab, tab + len);
  print_tab(tab, len);
  printf("is sorted: %s\n", check(is_sorted(tab, tab + len)));
}

void fixed_test(size_t len) {
  printf("Tests with sorted array:\n");
  int          *tab;
  tab = malloc(len * sizeof (int));
  for (size_t i = 0; i < len; ++i) {
    tab[i] = i;
  }
  run(tab, len);
  free(tab);
}

void fixed_test2(size_t len) {
  printf("Tests with revert sorted array:\n");
  int          *tab;
  tab = malloc(len * sizeof (int));
  for (size_t i = 0; i < len; ++i) {
    tab[i] = len - i;
  }
  run(tab, len);
  free(tab);
}

void random_test(size_t len) {
  printf("Tests with random array:\n");
  int          *tab;
  tab = malloc(len * sizeof (int));
  for (size_t i = 0; i < len; ++i) {
    tab[i] = (random() % (len * 5)) - 2 * len;
  }
  run(tab, len);
  free(tab);
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
    fixed_test2(size);
    random_test(size);
  }
  exit(0);
}
