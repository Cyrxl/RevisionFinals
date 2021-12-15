/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question08                */

#include <stdlib.h>
#include <unistd.h>

#ifndef _QUESTION08_H
#define _QUESTION08_H

/*
 * mystrncpy(dst,src,len) : copie au plus len caractères de la chaîne src dans
 * la chaîne dst.
 *
 * On suppose que src et dst sont non NULL, src est terminée par un '\0' et
 * dst est de taille suffisante.
 *
 * Dans tous les cas, mystrncpy(dst,src,len) écrit exactement len caractères
 * dans dst.
 *
 * Si le nombre de caractères de src est inférieur à len, alors votre fonction
 * devra remplir la fin de dst par des 0. Sinon (src plus grand que len) votre
 * fonction ne doit pas mettre de '\0' à la fin de dst.
 *
 * (voir strncpy(3))
 */
char *mystrncpy(char *dst, char *src, size_t len);

#endif
