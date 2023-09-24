#pragma once

#include "../LinealDataStructures/LinkedList/LinkedList.h"
#include "../Utils/SwitchArrayValues.h"

template <typename T>
void QuickSort(LinkedList<T> list, int start, int end) {

   if (end <= start) return;

   // Find new pivot
   int pivot = list[end];
   int i = start - 1;

   for (int j = start; j < end; j++) {
      if (list[j] < pivot) {
         i++;
         list.Swap(i, j);
      }
   }
   i++;
   list.Swap(end, i);
   //

   // run quick sort on left and right of pivot
   QuickSort(list, start, i - 1);
   QuickSort(list, i + 1, end);

   // choose last index for pivot

   // IF j is smaller than pivot increment i and swaap vaalues in j aand i

   // repeat until j reaches pivot, move i +1 aand  swap pivot with i
}
