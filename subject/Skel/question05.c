/* EPITA S3 2014/2015        */
/* Partiel 1 - December 2014 */
/* question05                */

#include "question05.h"

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* partition(int *left, int *right, int *pivot) {
    int p = *pivot;
    swap(pivot, right - 1);
    pivot = left;
    while (left != right - 1)
    {
        if (*left <= p)
        {
            swap(left, pivot);
            pivot = pivot + 1;
        }
        left++;
    }
    swap(pivot, right - 1);
    return pivot;
}

void quick_sort(int *left, int *right) {
  if (right - left == 0)
      return;
  int* pivot = (left) + (right - left) / 2;
  pivot = partition(left, right, pivot);
  quick_sort(left, pivot);
  quick_sort(pivot + 1, right);
}
