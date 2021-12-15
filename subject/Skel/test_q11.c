/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question11                */

#define QNUM 11
#define QOPT "seed size"
#define QNOPT 2

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "base_test.h"
#include "question11.h"

struct tree* build_tree(size_t depth, int *k) {
  struct tree          *t = NULL;
  if (depth) {
    *k += 1;
    t = malloc(sizeof (struct tree));
    t->key = *k;
    size_t              ld, rd;
    if (random() % 2) {
      ld = depth - 1;
      rd = depth - (1 + random() % (1 + depth/2));
    } else {
      rd = depth - 1;
      ld = depth - (1 + random() % (1 + depth/2));
    }
    t->left = build_tree(ld, k);
    t->right = build_tree(rd, k);
  }
  return t;
}

void print_tree(struct tree *t, int pad) {
  if (t) {
    printf("%*s(%d", pad, "", t->key);
    if (t->left == t->right)
      printf(")\n");
    else {
      printf("\n");
      print_tree(t->left, pad + 2);
      print_tree(t->right, pad + 2);
      printf("%*s)\n", pad, "");
    }
  }
}

void tests(size_t len) {
  printf("Tests:\n");
  struct tree          *t;
  int                   k = 0;
  t = build_tree(len, &k);
  print_tree(t, 0);
  size_t                max;
  max = 1 << (len + 1);
  int                  *keys;
  keys = calloc(max, sizeof (int));
  size_t                r;
  r = prefix_list(t, keys);
  printf("Size of t: %zu (in range: %s)\n", r, check(r < max));
  printf("Keys:\n  |");
  for (size_t i = 0; i < r && i < max; ++i) {
    printf(" %d |", keys[i]);
  }
  printf("\n");
}

int main(int argc,char *argv[]) {
  size_t                size;

  help_asked(argc,argv,QNUM,QOPT,QNOPT);

  if (argc <= QNOPT) {
    fprintf(stderr, "Parametres insuffisants.\n");
    usage(NULL,QNUM,QOPT);
  }
  else {
    seedInit(argv);
    size = getSize(argv);
    tests(size);
  }
  exit(0);
}
