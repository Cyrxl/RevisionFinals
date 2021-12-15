/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question02                */

# include "question02.h"

void bin_string(unsigned long n, char *output) {
    int index = 8 * sizeof(unsigned long) - 1;
    while (index >= 0)
    {
        output[index] = n % 2 + '0';
        n = n / 2;
        index--;
    }
}
