#pragma once

#include "../Utils/SwitchArrayValues.h"

void InsertionSort(int arr[], int size) {

   for (int i = 1; i < size; i++) {
      for (int j = i - 1; j >= 0; j--) {
         if (arr[j + 1] < arr[j])
            SwitchArrayValues(arr, j + 1, j);
         else
            break;
      }
   }
}