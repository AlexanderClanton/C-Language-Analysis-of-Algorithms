#include "insert.h"

#include "stats.h"

#include <stdio.h>
#include <stdlib.h>
//credit prof. long asgn3 pdf
// basic sort, takes the starting value and sees if the value next to it is larger
//then if it is move it from temp storage
//check the next
//then it resets after one chosen comparson and starts to the value next to it to compare
void insertion_sort(Stats *stats, uint32_t *A, uint32_t n) {
    uint32_t temp;
    uint32_t j = 0;
    for (uint32_t x = 0; x < n; x++) {
        j = x;
        temp = A[x];
        move(stats, A[x]);
        while (j > 0 && (cmp(stats, temp, A[j - 1]) == -1)) {
            A[j] = A[j - 1];
            move(stats, A[j]);
            j -= 1;
        }
        A[j] = temp;
        move(stats, A[j]);
    }

    return;
}
