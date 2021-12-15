/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question03                */

#include "question03.h"

unsigned long read_bin(char *input) {
    int index = 8 * sizeof(unsigned long) - 1;
    unsigned long toadd = 1;
    unsigned long res = 0;
    while (index >= 0)
    {
        if (input[index] == '1')
            res += toadd;
        toadd *= 2;
        index--;
    }

    return res;
}
