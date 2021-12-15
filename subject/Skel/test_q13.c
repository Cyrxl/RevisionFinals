/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question13                */

# define QNUM 13
# define QOPT ""
# define QNOPT 0

# include <fcntl.h>
# include <sys/mman.h>
# include <sys/stat.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "base_test.h"
# include "question13.h"

void printmsg(char *m, size_t len) {
  for (char *cur = m; cur != m + len; ++cur) {
    switch (*cur) {
    case '*': printf("\x1b[37;6m*\x1b[0m"); break;
    case 'i': printf("\x1b[36;1mi\x1b[0m"); break;
    case 'o': printf("\x1b[35;5mo\x1b[0m"); break;
    case '>': printf("\x1b[43m>\x1b[0m"); break;
    case '<': printf("\x1b[42m<\x1b[0m"); break;
    default: printf("%c", *cur);
    }
  }
}

int main(int argc,char *argv[])
{
  help_asked(argc,argv,QNUM,QOPT,QNOPT);

  char          key[] = "tocard";
  char         *msg;
  int fd = open("message", O_RDONLY, 0666);

  struct stat   stat;
  fstat(fd, &stat);

  msg = mmap(NULL, stat.st_size, PROT_READ|PROT_WRITE, MAP_PRIVATE, fd, 0);
  close(fd);

  decipher(msg, stat.st_size, key, sizeof (key));
  printmsg(msg, stat.st_size);

  exit(0);
}
