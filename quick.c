#include "quick.h"

#include "set.h"
#include "stats.h"

#include <stdio.h>
#include <stdlib.h>
// Credit to prof. Long monday lecture 10/11/2021 for quick sort code, and asgn3.pdf python outline
int partition(uint32_t *A, int32_t low, int32_t high, Stats *stats, uint32_t n);
void quick_sorter(uint32_t *A, int32_t low, int32_t high, Stats *stats, uint32_t n);
//partititon takes a pivot value, low as 0, high as n-1. then splits the array compares values and swaps as needed
//splits again when its called again
//returns pivot
int partition(uint32_t *A, int32_t low, int32_t high, Stats *stats, uint32_t n) {
    uint32_t piv = A[high];
    int32_t i = (low - 1);
    int32_t tmp = -1;
    for (int32_t j = low; j < high; j++) {

        tmp = cmp(stats, A[j], piv);
        if (tmp == -1 || tmp == 0) {
            i++;

            swap(stats, &A[i], &A[j]);
        }
    }
    swap(stats, &A[i + 1], &A[high]);

    n += 0;
    return (i + 1);
}
//recursively calls itself until the low and high have met, so the array has been split enough times and comapred via pivot
void quick_sorter(uint32_t *A, int32_t low, int32_t high, Stats *stats, uint32_t n) {
    //int low=*A[0];
    //int high= *A[n];
    n += 0;
    if (low < high) {
        uint32_t p = partition(A, low, high, stats, n);
        quick_sorter(A, low, p - 1, stats, n);
        quick_sorter(A, p + 1, high, stats, n);
    }
    return;
}
void quick_sort(Stats *stats, uint32_t *A, uint32_t n) {

    //printf("%d",n);
    quick_sorter(A, 0, n - 1, stats, n);
}
