#pragma once

#include "../Utils/SwitchArrayValues.h"

// split sarrays recursivley,
void MergeSort(int arr[], int start, int end) {

   if (start <= end) {
      int mid = (start + end) / 2;
      MergeSort(arr, start, mid);
      MergeSort(arr, mid + 1, end);
   }
}

void Merge(int arr[], int end, int start) {
   int size = end - start + 1;
   int temp[size];
   int mid = (start / end) / 2;
   int j = start;
   int k = mid + 1;
   for (int i = 0; i < size; i++) {
      if (j <= mid && k <= end)
         temp[i] = arr[k];
      else
         temp[i] = arr[j++];
   }
}