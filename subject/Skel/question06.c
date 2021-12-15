/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question06                */

#include "question06.h"
#include <stdlib.h>

void insert(struct list *l, int x) 
{
    while (l->next && l->next->val <= x)
    {
        l = l->next;
    }

    if (l && l->val != x)
    {
        struct list *new = malloc(sizeof(struct list));
        new->val = x;
        new->next = l->next;
        l->next = new;
    }
}
