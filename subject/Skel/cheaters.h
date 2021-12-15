/* Prevent string.h usage */

#ifndef _CHEATERS_H_
#define _CHEATERS_H_

#define _CHEATER_ ({ write(STDOUT_FILENO,"CHEATER !\n",10); abort(); })

#define strlen(x)        ({ _CHEATER_; x=x; })
#define strncpy(d,s,l)   ({ _CHEATER_; s=s; l=l; d=d; })
#define strlcpy(d,s,l)   ({ _CHEATER_; s=s; l=l; d=d; })
#define memcpy(d,s,l)    ({ _CHEATER_; s=s; l=l; d=d; })
#define bcopy(s,d,l)     ({ _CHEATER_; s=s; l=l; d=d; })
#define strcpy(d,s)      ({ _CHEATER_; s=s; d=d; })
#define memccpy(d,s,c,l) ({ _CHEATER_; s=s; l=l; c=c; d=d; })
#define strchr(s,c)      ({ _CHEATER_; s=s; c=c; })
#define strncmp(s1,s2,l) ({ _CHEATER_; s1=s1; s2=s2; c=c; })
#define strcmp(s1,s2)    ({ _CHEATER_; s1=s1; s2=s2; })
#define pow(x,p)         ({ _CHEATER_; x=x; p=p; })
#define powf(x,p)        ({ _CHEATER_; x=x; p=p; })
#define powl(x,p)        ({ _CHEATER_; x=x; p=p; })
#define sqrt(x)          ({ _CHEATER_; x=x; })

#endif
