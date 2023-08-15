#include "shell.h"

#include "stats.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int gap(uint32_t n);
//credit to prof. long asgn3 pdf
//shell is similar to insert but instead of comparing every value it creates a gap, in this case knuth. then compares those values until gap is 1
//returns nothing
void shell_sort(Stats *stats, uint32_t *A, uint32_t n) {

    uint32_t y, j = 0;
    uint32_t temp;
    uint32_t gap1;
    gap1 = gap(n);
    if (n == 2 && gap1 == 0) { //is gap is 0 fix. aka 2 values in an array
        if ((cmp(stats, A[1], A[0]) == -1)) {
            swap(stats, &A[1], &A[0]);
        }
    }
    while (gap1 > 0) {
        for (y = gap1; y < n; y++) {
            j = y;
            temp = A[y];
            move(stats, A[y]);
            while ((j >= gap1) && (cmp(stats, temp, A[j - gap1]) == -1)) {
                A[j] = A[j - gap1];
                move(stats, A[j - gap1]);
                j -= gap1;
            }
            A[j] = temp;
            move(stats, temp);
        }
        gap1 = (gap1 - 1) / 3;
    }

    return;
}

//knuth formula n*3+1
//used, returns knuth gap
int gap(uint32_t n) {

    uint32_t increment = 0;
    while (increment < n / 3) {
        increment *= 3;
        increment += 1;
    }
    return increment;
}
