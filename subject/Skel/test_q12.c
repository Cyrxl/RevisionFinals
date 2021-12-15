/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question12                */

#define QNUM 12
#define QOPT "seed size"
#define QNOPT 2

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "base_test.h"
#include "question12.h"

struct image* whiteimg(size_t depth) {
  struct image         *img;
  img = calloc(1, sizeof (struct image));
  img->white = 1;
  if (depth) {
    img->white = 0;
    img->upleft    = whiteimg(depth - 1);
    img->upright   = whiteimg(depth - 1);
    img->downleft  = whiteimg(depth - 1);
    img->downright = whiteimg(depth - 1);
  }
  return img;
}

struct image* blackimg(size_t depth) {
  struct image         *img = NULL;
  if (depth) {
    img = calloc(1, sizeof (struct image));
    img->upleft    = blackimg(depth - 1);
    img->upright   = blackimg(depth - 1);
    img->downleft  = blackimg(depth - 1);
    img->downright = blackimg(depth - 1);
  }
  return img;
}

struct image* randomimg(size_t depth) {
  struct image         *img = NULL;
  if (depth) {
    img = calloc(1, sizeof (struct image));
    img->upleft    = randomimg(depth - (1 + random() % depth));
    img->upright   = randomimg(depth - (1 + random() % depth));
    img->downleft  = randomimg(depth - (1 + random() % depth));
    img->downright = randomimg(depth - (1 + random() % depth));
  } else {
    if (random()%2)
      img = whiteimg(0);
  }
  return img;
}

void deleteimg(struct image *img) {
  if (img) {
    if (!(img->white)) {
      deleteimg(img->upleft);
      deleteimg(img->upright);
      deleteimg(img->downleft);
      deleteimg(img->downright);
    }
    free(img);
  }
}

# define BLACK '.'
# define WHITE '#'

void displayimg(struct image *img, char *map, size_t max, size_t x, size_t y, size_t len) {
  if (img == NULL || img->white) {
    char        pix;
    pix = img == NULL ? BLACK : WHITE;
    for (size_t i = x; i < x + len; ++i) {
      for (size_t j = y; j < y + len; ++j) {
        map[i * max + j] = pix;
      }
    }
  } else {
    displayimg(img->upleft, map, max, x, y, len / 2);
    displayimg(img->upright, map, max, x, y + len / 2, len / 2);
    displayimg(img->downleft, map, max, x + len / 2, y, len / 2);
    displayimg(img->downright, map, max, x + len / 2, y + len / 2, len / 2);
  }
}

void printimg(char *map, size_t max) {
  for (size_t i = 0; i < max * max; i += max) {
    printf("%.*s\n", (int)max, map + i);
  }
}

int testimg(struct image *img, size_t size) {
  size_t                max;
  max = 1 << size;
  char                 *map;
  map = calloc(max * max + 1, sizeof (char));
  displayimg(img, map, max, 0, 0, max);
  printimg(map, max);
  int           iw;
  iw = is_white(img);
  printf("is_white: %s", iw ? "yes" : "no");
  return iw;
}

void fixed_test(size_t size) {
  printf("fixed tests:\n");
  struct image         *img;
  img = whiteimg(size);
  printf(" (%s)\n", check(testimg(img, size)));
  deleteimg(img);
  img = blackimg(size);
  printf(" (%s)\n", check(!testimg(img, size)));
  deleteimg(img);
  printf("random tests:\n");
  img = randomimg(size);
  testimg(img, size);
  printf("\n");
  deleteimg(img);
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
    fixed_test(size);
    // rand_test(size);
  }
  exit(0);
}
