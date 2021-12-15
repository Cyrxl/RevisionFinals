/* Some macro */

#include <stdarg.h>
#include <stdlib.h>

#ifndef _SKEL_H_
#define _SKEL_H_

static inline __attribute__((noreturn))
void to_be_removed(void *x __attribute__((unused)),...) {
  abort();
}

#define REMOVE_ME(args...) to_be_removed(NULL,args)

#endif
