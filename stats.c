#include "stats.h"

#include "set.h"

#include <stdio.h>
#include <stdlib.h>

int cmp(Stats *stats, uint32_t x, uint32_t y) {
    (*stats).compares += 1;
    if (x < y) {
        return -1;
    }
    if (x == y) {
        return 0;
    }

    if (y > x) {
        return 1;
    }
    return -10;
}

uint32_t move(Stats *stats, uint32_t x) {
    (*stats).moves += 1;
    return x;
}

void swap(Stats *stats, uint32_t *x, uint32_t *y) {
    uint32_t hold;
    hold = *x;
    *x = *y;

    *y = hold;
    (*stats).moves += 3;
    return;
}

void reset(Stats *stats) {
    (*stats).moves = 0;
    (*stats).compares = 0;
    return;
}
