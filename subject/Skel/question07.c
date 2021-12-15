/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question07                */

#include "question07.h"

int circular_list_mem(struct list *l, int x) {
    int sent = l->val;
    if (sent == x)
        return 1;
    l = l->next;

    while(l->val != sent)
    {
        if (l->val == x)
            return 1;
        l = l->next;
    }

    return 0;
}
