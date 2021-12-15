/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question08                */

#define QNUM 8
#define QOPT "seed size"
#define QNOPT 2

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "base_test.h"
#include "question08.h"

static
void checkcopy(char src[], size_t size, size_t _end) {
  size_t        end = _end || size ? _end : 1;
  char          *dst;
  size_t        lastchar = end<size ? end - 1 : size - 1;
  dst = calloc(end + 1,1);
  dst[end] = (char)255;
  printf("\ntest: mystrncpy(dst,src,%zu)\n",end);
  mystrncpy(dst,src,end);

  if (end)
    printf("dst = \"%.*s\"\n-- check:\n",(int)end,dst);
  else
    printf("-- check:\n");

  if ( end && size ) {
    printf("  first char: %s\n",check(dst[0] == src[0]));
    printf("  last char: %s\n",check(dst[lastchar] == src[lastchar]));
  }

  if (end > size) {
    int ok = 1;
    for (size_t i = size; ok && i < end; ++i)
      ok = dst[i] == 0;
    printf("  0 fill: %s\n",check(ok));
  }

  printf("  overflow: %s\n",check(dst[end]==(char)255));
  free(dst);
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
    char       *src = calloc(4 + (((size + 4) >> 2)<<2), 1);
    randstr(src,size);
    src[size] = 0;
    src[size+1] = 255;
    printf("src = \"%s\"\n",src);

    if (size) {
      checkcopy(src,size,size + 1);
      if (src[size] != 0 || src[size + 1] != (char)255) abort();
      checkcopy(src,size,size / 2);
      if (src[size] != 0 || src[size + 1] != (char)255) abort();
      checkcopy(src,size,size * 2);
      if (src[size] != 0 || src[size + 1] != (char)255) abort();
      checkcopy(src,size,0);
      if (src[size] != 0 || src[size + 1] != (char)255) abort();
    } else {
      checkcopy(src,size,1);
      if (src[size] != 0 || src[size + 1] != (char)255) abort();
    }
  }
  exit(0);
}
