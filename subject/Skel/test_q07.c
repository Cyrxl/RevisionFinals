/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question07                */

#define QNUM 7
#define QOPT "seed size"
#define QNOPT 2

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "base_test.h"
#include "question07.h"

void list_print(struct list *l) {
  if (l) {
    struct list        *cur = l;
    do {
      printf("(%d)->", cur->val);
      cur = cur->next;
    } while (cur != l);
    printf("...\n");
  } else {
    printf("Empty\n");
  }
}

struct list* build_circular(size_t len) {
  struct list          *l = NULL;
  if (len) {
    l = malloc(sizeof (struct list));
    l->val = random() % (1 + len * 4);
    l->next = l;
    do {
      struct list      *cur;
      cur = malloc(sizeof (struct list));
      cur->val = random() % (1 + len * 4);
      cur->next = l->next;
      l->next = cur;
      len--;
    } while (len > 1);
  }
  return l;
}

void random_test(size_t len) {
  printf("Random Tests:\n");
  struct list          *l;
  l = build_circular(len);
  printf("Random circular list:\n  ");
  list_print(l);
  for (size_t i = 0; i <= len; ++i) {
    int         n = random() % (1 + len * 4);
    printf("  circular_list_mem(l, %d): \t", n);
    if (circular_list_mem(l, n)) {
      printf("found\n");
    } else {
      printf("not found\n");
    }
  }
}

int main(int argc,char *argv[]) {
  size_t                size;

  help_asked(argc,argv,QNUM,QOPT,QNOPT);

  if (argc <= QNOPT) {
    fprintf(stderr, "Parametres insuffisants.\n");
    usage(NULL,QNUM,QOPT);
  } else {
    seedInit(argv);
    size = getSize(argv);
    random_test(size);
  }
  exit(0);
}
