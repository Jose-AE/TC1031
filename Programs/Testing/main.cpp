#include "../../Utils/Functions/PrintArray.h"
#include "../../Utils/SortMethods/InsertionSort.h"

int main(int argc, char const *argv[]) {
   int arr[] = {5, 5, 9, 3, 4, 2};

   InsertionSort(arr, 6);
   PrintArray(arr, 6);

   return 0;
}
