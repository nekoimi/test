//
// Created by nekoimi on 2021/9/9.
//
#include <stdio.h>
#include "squares_of_sorted_array.h"

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; ++i) {
        printf("%d, ", nums[i]);
    }
    return nums;
}

void do_sorted_squares() {
    int numbers[3] = {-4, 2, 9};
    int returnSize = 0;
    sortedSquares(numbers, 3, &returnSize);
}
