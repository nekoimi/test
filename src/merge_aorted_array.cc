//
// Created by nekoimi on 2021/6/24.
//
#include <stdio.h>
#include "merge_sorted_array.h"

void do_quick_sort(int *arr, int start, int end) {
    int i, j , stand;
    // Here must be need check start/end default value!
    if (start > end) {
        return;
    }

    // Select first value to stand
    stand = arr[start];
    i = start;
    j = end;
    // Run, find direction ( i -> | <- j )
    while (i != j) {
        while (i < j && arr[j] >= stand) {
            j--;
        }

        while (i < j && arr[i] <= stand) {
            i++;
        }

        if (i < j) {
            arr[i] = arr[i] ^ arr[j];
            arr[j] = arr[i] ^ arr[j];
            arr[i] = arr[i] ^ arr[j];
        }
    }

    arr[start] = arr[i];
    arr[i] = stand;

    do_quick_sort(arr, start, i - 1);
    do_quick_sort(arr, i + 1, end);
}

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    int length = m + n;
    for (int j = 0; j < n; ++j) {
        nums1[m + j] = nums2[j];
    }
    for (int i = 0; i < length; ++i) {
        printf("n1->%d: %d \n", i, nums1[i]);
    }
    printf("\n");
    do_quick_sort(nums1, 0, length - 1);
    for (int i = 0; i < length; ++i) {
        printf("n1->%d: %d \n", i, nums1[i]);
    }
}

void run_merge() {
    int n1[7] = {9, 37, 23, 0, 0, 0, 0};
    int n2[3] = {10, 2, 0};
    merge(n1, 7, 3, n2, 2, 2);
}

