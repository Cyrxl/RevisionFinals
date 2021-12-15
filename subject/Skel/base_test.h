/* Base functions for testing exam */

#ifndef _BASE_TEST_H
#define _BASE_TEST_H
void print_usage(FILE *f,int qnum, const char *qopt);
void usage(char *s,int qnum, const char *qopt);
void help_asked(int ac, char *av[], int qnum, const char *qopt, int qnopt);

static inline
char randchar()
{
  return 32 + random()%95;
}

static inline
void randstr(char s[], size_t size)
{
  for (size_t i=0; i<size; ++i)
    s[i] = randchar();
}

#define seedInit(_av) (srandom((unsigned)(1+strtoul((_av)[1], NULL, 10))))
#define getSize(_av)  (strtoull((_av)[2], NULL, 10))
#define getMax(_av)   (atoi((_av)[3]))

#define check(C__) ((C__) ? "\x1b[44mOK\x1b[0m" : "\x1b[41mKO\x1b[0m")

#endif
