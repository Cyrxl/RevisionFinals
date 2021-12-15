/* Base functions for testing exam */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "base_test.h"


/* print usage message on given stream */
void print_usage(FILE *f,int qnum, const char *qopt)
{
  fprintf(f,"Question %02d:\n./question%02d %s\n",qnum,qnum,qopt);
  fprintf(f,"  -help   Display this list of options\n");
  fprintf(f,"  --help  Display this list of options\n");
}

/* show usage and die ! */
__attribute__((noreturn))
void usage(char *s,int qnum, const char *qopt) {
  if (s)
    fprintf(stderr,"Parametre non reconnu: %s\n",s);
  print_usage(stderr,qnum,qopt);
  exit (1);
}

/* Detection du -help/--help */
void help_asked(int ac, char *av[], int qnum, const char *qopt, int qnopt)
{
  int i,j,h;
  int end = (qnopt+1) < ac ? qnopt+1 : ac;
  const char *help = "help";
  if (ac>1)
    for (i=1; i<end; i++)
      if (av[i][0] == '-')
	{
	  if (!(av[i][1])) usage(av[i],qnum,qopt);
	  j = av[i][1]=='-'?2:1 ;
	  h = 1;
	  while (h && av[i][j] && *help)
	    h = (av[i][j++] == *(help++));
	  if (h && !*help && !av[i][j])
	    {
	      print_usage(stdout,qnum, qopt);
	      exit(0);
	    }
	  else
	    usage(av[i],qnum,qopt);
	}
}


