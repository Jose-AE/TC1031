#pragma once

int BinarySearch(int arr[], int size, int target) {
   int leftIndex = 0;
   int rightIndex = size - 1;

   while (leftIndex <= rightIndex) {
      int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

      if (arr[middleIndex] == target)
         return middleIndex;
      else if (arr[middleIndex] > target)
         rightIndex = middleIndex - 1;
      else
         leftIndex = middleIndex + 1;
   }

   return -1;
}