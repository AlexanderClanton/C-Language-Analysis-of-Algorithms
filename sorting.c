#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OPTIONS "aeisqrnph"
#include "heap.h"
#include "insert.h"
#include "quick.h"
#include "set.h"
#include "shell.h"
#include "stats.h"
//maybe remove?
#include <stdbool.h>
//partial code from prof.long
//purpose is to recieve input from user command line, for the type of sort. and if they want to set seed, terms. and num of printed terms
//take that -input, and then assign what input into a set. which has a integer representing the sort
//take the true false and the tracked number of inputs into a for loop if/else
//if the input is true for a function print out the sort
//takes int arg, and double pointer argv
//returns 0 as its main
//0 is heao, 1 is insert, 2 is shell, 3 is quick, 5 is seed, 6 is number of terms, 7 is printed terms

int main(int argc, char **argv) {

    Stats stat;
    reset(&stat);
    uint32_t *heap_point1;
    uint32_t *heap_point2;
    uint32_t *heap_point3;
    uint32_t *heap_point4;
    Set s = empty_set();
    //s=insert(0,s);
    int track = 0, opt = 0; //term1 = 0;
    //double output1 = 0, sqrt_hold = 0, diff = 0;
    //int tru_val[10] = { 0 };
    int input_val[3] = {
        0
    }; // [0] is stored for seed, [1] stores the value of size, [2] stores the printed terms
    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        //switch case takes input from command line
        //while loop until all input is gone through
        switch (opt) {
        case 'a': //for -a
            //make all of em true, dont think a for loop is worth it
            s = insert_set(0, s); // 0 is heap
            s = insert_set(1, s); //1 is insertion
            s = insert_set(2, s); //2 is shell
            s = insert_set(3, s); //3 is quick
            track = 4;
            //call all tests
            break;
        case 'e': // -e
            // call heapsort
            ++track;
            s = insert_set(0, s);
            break;
        case 'i': //for -b
            s = insert_set(2, s);
            ++track;

            //insertion sort
            break;
        case 's': // for -m
            s = insert_set(1, s);
            ++track;
            //shell sort
            break;
        case 'q': // for -r
            s = insert_set(3, s);
            //quick sort
            ++track;
            break;
        case 'r': // for -v

            input_val[0] = atoi(argv[optind]);
            if (input_val[0] < 0) { //input_val[0]==NULL// this if is incase of bad input
                input_val[0] = 13371453;
                s = insert_set(5, s); //incorrect seed
                break;
            } // CHECK** later that its an int
            //seed
            s = insert_set(5, s); //correct seed
            break;
        case 'n': // for -n
            input_val[1] = atoi(argv[optind]);
            if (input_val[1] < 1) { //for bad input
                input_val[1] = 100;
                s = insert_set(6, s); //incorrect size
                break;
            }
            s = insert_set(6, s); //correct size
            //size of random array
            break;
        case 'p': // for -s
            input_val[2] = atoi(argv[optind]);
            if (input_val[2] > input_val[1]) { //bad input
                input_val[2] = input_val[1];
                s = insert_set(7, s); //incorrect -p
                break;
            }

            //print num of term stats for each function
            s = insert_set(7, s); //correct -p
            break;
        case 'h': // -h
            s = insert_set(8, s);
            //display help prompt
            break;
        }
    }
    //these 3 if are if the user decides no input for -r,-n -p. so go to default values
    if ((member_set(5, s)) == false) {

        input_val[0] = 13371453;
    }
    if ((member_set(6, s) == false)) {
        input_val[1] = 100;
    }
    if ((member_set(7, s) == false)) {
        if (input_val[1] > 100) {
            input_val[2] = 100;

        } else {
            input_val[2] = input_val[1];
        }
    }
    int random_hold = 0;
    srandom(input_val[0]); //input_val[0] holds the seed value
    //dynamic allocation for cs.swarthmore.edu for the outline for malloc and check null
    heap_point1 = (uint32_t *) malloc(sizeof(uint32_t) * input_val[1]);
    if (heap_point1 == NULL) {
        printf("YO HOW DID THIS HAPPEN, ERROR NO GOOD");
        return -1; //the idiot made the array to big
    }
    //creation of 4 random arrays
    heap_point2 = (uint32_t *) malloc(sizeof(uint32_t) * input_val[1]);
    heap_point3 = (uint32_t *) malloc(sizeof(uint32_t) * input_val[1]);
    heap_point4 = (uint32_t *) malloc(sizeof(uint32_t) * input_val[1]);
    for (int x = 0; x < input_val[1]; x++) {
        random_hold = random() % (1 << 30); //fill them for up to size 30 bit
        heap_point1[x] = random_hold;
        heap_point2[x] = random_hold;
        heap_point3[x] = random_hold;
        heap_point4[x] = random_hold;
    }

    for (int x = 0; x < track; x++) {
        if ((member_set(8, s) == true)) {
            printf("SYNOPSIS\n"); //help prompt
            printf("   A collection of comparison-based sorting algorithms.\n\n");
            printf("USAGE\n   ./sorting [-haeispn:p:r:] [-n length] [-p elements] [-r seed]\n\n");
            printf("OPTIONS\n\n");
            printf("  -h             display program help and usage.\n");
            printf("  -a             enable all sorts.\n");
            printf("  -i             enable Heap Sort\n");
            printf("  -s             enable Insertion Sort.\n");
            printf("  -q             enable Quick Sort.\n");
            printf("  -n length      specify number of array elements (default: 100).\n");
            printf("  -p elements    specify number of elements to print (default: 100).\n");
            printf("  -r seed        specify random seed (default: 13371453).\n");
            return 0;
        }

        if (member_set(0, s) == true) { // if -e then print e value
            heap_sort(&stat, heap_point1, input_val[1]);

            printf("Heap Sort, %d elements, %lu moves, %lu compares\n", input_val[1], stat.moves,
                stat.compares);
            for (int z = 0; z < input_val[2]; z++) {
                if (z % 5 == 0 && z != 0) {
                    printf("\n");
                }
                printf("%13d", heap_point1[z]);
            }
            if (input_val[2] != 0) {
                printf("\n"); //so if no print we get correct spacing
            }

            s = delete_set(0, s); //gets rid of it, so we dont repeat
            reset(&stat); //no stat problems
            //tru_val[1] = false; // were done, its false dont print again
        } else if (member_set(1, s) == true) { //if user inputted the -r for euler series print

            shell_sort(&stat, heap_point2, input_val[1]);

            printf("Shell Sort, %d elements, %lu moves, %lu compares\n", input_val[1], stat.moves,
                stat.compares);
            for (int z = 0; z < input_val[2]; z++) {
                if (z % 5 == 0 && z != 0) {
                    printf("\n");
                }
                printf("%13d", heap_point2[z]);
            }
            if (input_val[2] != 0) {
                printf("\n");
            }

            s = delete_set(1, s);
            reset(&stat);
            // tru_val[4] = false; // dont repeat this again, false

        } else if (member_set(2, s) == true) { // user put in -b

            insertion_sort(&stat, heap_point3, input_val[1]);
            printf("Insertion Sort, %d elements, %lu moves, %lu compares\n", input_val[1],
                stat.moves, stat.compares);
            for (int z = 0; z < input_val[2]; z++) {
                if (z % 5 == 0 && z != 0) {
                    printf("\n"); //every 5th
                }
                printf("%13d", heap_point3[z]);
            }
            if (input_val[2] != 0) {
                printf("\n");
            }

            s = delete_set(2, s);
            reset(&stat);
            //tru_val[2] = false; // dont repeat again
        } else if (member_set(3, s) == true) { // if user entered -m

            quick_sort(&stat, heap_point4, input_val[1]);

            printf("Quick Sort, %d elements, %lu moves, %lu compares\n", input_val[1], stat.moves,
                stat.compares);
            for (int z = 0; z < input_val[2]; z++) {
                if (z % 5 == 0 && z != 0) {
                    printf("\n"); //prints every 5th
                }
                printf("%13d", heap_point4[z]);
            }
            if (input_val[2] != 0) {
                printf("\n");
            }

            s = delete_set(3, s);
            reset(&stat);
            // dont repeat this again
        }
    }
    free(heap_point4); //free the memoru from what we used
    free(heap_point3);
    free(heap_point2);
    free(heap_point1);
    return 0;
}
