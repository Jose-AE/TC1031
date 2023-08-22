// #include "../../Functions/SortMethods/BubbleSort.h"
#include "../../Functions/SortMethods/BubbleSort.h"
#include "../../Functions/Utils/PrintArray.h"
#include "../../Functions/Utils/SwitchArrayValues.h"

int main(int argc, char const* argv[]) {
   int arr[] = {5, 5, 9, 3, 4, 2};

   BubbleSort(arr, 6);

   PrintArray(arr, 6);

   return 0;
}
