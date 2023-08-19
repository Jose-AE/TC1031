#pragma once

#include "../Utils/SwitchArrayValues.h"

void SelectionSort(int arr[], int size) {
   for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
         if (arr[j] > arr[i]) SwitchArrayValues(arr, i, j);
      }
   }
}
