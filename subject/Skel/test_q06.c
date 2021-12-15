/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question06                */

#define QNUM 6
#define QOPT "seed size"
#define QNOPT 2

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "base_test.h"
#include "question06.h"

static
int is_sorted(struct list *l) {
  for (struct list *cur = l->next; cur->next; cur = cur->next) {
    if (cur->val > cur->next->val) return 0;
  }
  return 1;
}

static
void list_print(struct list *l) {
  for (struct list *cur = l; cur->next; cur = cur->next) {
    printf("(%d)->", cur->next->val);
  }
  printf("NULL\n");
}

static
void random_test(size_t len) {
  printf("RANDOM TESTS:\n");
  printf("  Inserting into an empty list:\n");
  struct list          *l;
  l = malloc(sizeof (struct list));
  l->next = NULL;
  l->val = -len - 1;
  for (size_t i = 0; i < len; ++i) {
    int         n = random() % (len * 3) - len;
    printf("    inserting: %d\n", n);
    insert(l, n);
  }
  printf("Sentinel untouched:  %s\n", check(l->val ==  - (int)len - 1));
  printf("List after insertions:\n  ");
 list_print(l);
  printf("List is sorted: %s\n", check(is_sorted(l)));
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
