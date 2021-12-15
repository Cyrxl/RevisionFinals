/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question04                */

#include "question04.h"
#include <stddef.h>

int* binsearch(int *begin, int *end, int x) {
    while (begin != end)
    {
        int* mid = (begin) + (end - begin) / 2;
        if (*mid == x)
            return mid;
        else if (*mid < x)
            begin = mid + 1;
        else
            end = mid;
    }
    return NULL;
}
