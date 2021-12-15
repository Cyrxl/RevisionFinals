/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question02                */

#define QNUM 2
#define QOPT "seed size"
#define QNOPT 2

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "base_test.h"
#include "question02.h"

void fixed_test(void) {
  char                 *output;
  output = calloc(1 + 8 * sizeof (unsigned long), 1);
  unsigned long         data[] = {1, 2, 3, 4, 42};
  char                 *bin[] = {
    "1", "10", "11", "100", "101010"
  };
  printf("Fixed test:\n");
  for (size_t i = 0; i < 5; ++i) {
    unsigned long       n;
    n = data[i];
    bin_string(n, output);
    output[8 * sizeof (unsigned long)] = 0;
    printf("  bin_string(%2lu) = \"%s\" (should be %s)\n", n, output, bin[i]);
  }
  free(output);
}

void random_test(size_t len) {
  char                 *output;
  output = calloc(1 + 8 * sizeof (unsigned long), 1);
  printf("Random test:\n");
  for (size_t i = 0; i < len; ++i) {
    unsigned long       n;
    n = (((unsigned long)random()) << 33) + random();
    bin_string(n, output);
    output[8 * sizeof (unsigned long)] = 0;
    printf("  bin_string(%20lu) = \"%s\"\n", n, output);
  }
  free(output);
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
