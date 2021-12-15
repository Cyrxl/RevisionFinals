/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question03                */

#define QNUM 3
#define QOPT "seed size"
#define QNOPT 2

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "base_test.h"
#include "question03.h"

void zerofill(char *s, char *num, size_t len_num) {
  size_t                len, i;
  len = 8 * sizeof (unsigned long);
  for (i = 0; i < len - len_num; ++i) {
    s[i] = '0';
  }
  for (; i < len; ++i) {
    s[i] = num[(len_num + i) - len];
  }
}

void fixed_test(void) {
  char                 *input;
  input = calloc(1 + 8 * sizeof (unsigned long), 1);
  unsigned long         data[] = {1, 2, 3, 4, 42};
  char                 *bin[] = {
    "1", "10", "11", "100", "101010"
  };
  size_t                len[] = { 1, 2, 2, 3, 6};
  printf("Fixed test:\n");
  for (size_t i = 0; i < 5; ++i) {
    zerofill(input, bin[i], len[i]);
    input[8 * sizeof (unsigned long)] = 0;
    printf("  read_bin(%s) = %lu (should be %lu)\n", input, read_bin(input), data[i]);
  }
  free(input);
}

void random_test(size_t len) {
  char                 *input;
  input = calloc(1 + 8 * sizeof (unsigned long), 1);
  printf("Random test:\n");
  for (size_t i = 0; i < len; ++i) {
    for (unsigned i = 0; i < 8 * sizeof (unsigned long); ++i)
      input[i] = '0' + (random() % 2);
    input[8 * sizeof (unsigned long)] = 0;
    printf("  read_bin(%s) = %lu\n", input, read_bin(input));
  }
  free(input);
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
