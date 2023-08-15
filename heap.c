#include "heap.h"

#include "set.h"
#include "stats.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//credit to prof long
int max_child(Stats *stats, uint32_t *A, uint32_t n, int32_t first, int32_t last);
void fix_heap(Stats *stats, uint32_t *A, uint32_t n, int32_t first, int32_t last);
void build_heap(Stats *stats, uint32_t *A, uint32_t n, int32_t first, int32_t last);
// this takes two kids and finds the max
////returns the left or right depending on  which child is bigger as this is max heap
int max_child(Stats *stats, uint32_t *A, uint32_t n, int32_t first, int32_t last) {
    n += 0;
    int32_t left = 2 * first; //children are in arrays, child can be found 2k
    int32_t right = left + 1; // 2k+1
    int32_t tmp = 0;

    if ((right <= last) == true) {
        tmp = cmp(stats, A[right - 1], A[left - 1]);
    }

    if ((right <= last) && (A[right - 1] > A[left - 1])) {
        return right;
    }
    return left;
}
//reorder the heap when a node in the tree is moved to be correct max heap order
//returns nothing as it changes A via a pointer
void fix_heap(Stats *stats, uint32_t *A, uint32_t n, int32_t first, int32_t last) {
    bool found = false;
    int32_t mother = first;
    int32_t great = max_child(stats, A, n, mother, last);
    n += 0;

    while ((mother <= (last / 2)) && !found) {

        cmp(stats, A[mother - 1], A[great - 1]);

        if (A[mother - 1] < A[great - 1]) {

            swap(stats, &A[mother - 1], &A[great - 1]);
            mother = great;
            great = max_child(stats, A, n, mother, last);

        } else {
            found = true;
        }
    }

    return;
}
//bulids the heap from father node, can only bulid when the heap is fixed
//returns nothing
void build_heap(Stats *stats, uint32_t *A, uint32_t n, int32_t first, int32_t last) {
    int32_t father1 = last / 2;
    int32_t test = first - 1;
    //maybe a compares?
    for (int32_t father = father1; father > test; father += -1) {
        fix_heap(stats, A, n, father, last);
    }
}
//gets the first value as 1ast chosen as last
//call bulid heap, swaps value when a value doesnt follow max heap rules
//then fix
//return nothing
void heap_sort(Stats *stats, uint32_t *A, uint32_t n) {
    int32_t first = 1;
    int32_t last = n; //bug check this
    build_heap(stats, A, n, first, last);
    for (int32_t leaf = last; leaf > first; leaf += -1) {
        swap(stats, &A[first - 1], &A[leaf - 1]);
        fix_heap(stats, A, n, first, leaf - 1);
    }
}
