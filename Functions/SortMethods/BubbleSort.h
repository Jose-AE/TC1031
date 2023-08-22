#pragma once

#include "../Utils/SwitchArrayValues.h"

void BubbleSort(int arr[], int size) {

   bool sorted = false;
   while (!sorted) {
      sorted = true;
      for (int i = 0; i < size - 1; i++) {
         if (arr[i] > arr[i + 1]) {
            sorted = false;
            SwitchArrayValues(arr, i, i + 1);
         }
      }
   }
}