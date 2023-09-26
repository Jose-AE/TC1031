#include <iostream>

int BinarySearch(int arr[], int length, int target) {

   int middle = length / 2;

   while (true) {
      if (target > arr[middle])
         middle = middle / 2;
      else if (target < arr[middle])
         middle = middle + middle / 2;
      else if (arr[middle] == target)
         break;
      else {
         middle = -1;
         break;
      }
   }
   return middle;
}

int LinearSearch(int arr[], int length, int target) {
   int index = -1;

   for (int i = 0; i < length; i++) {
      if (arr[i] == target) index = i;
   }
   return index;
}

int main(int argc, char const *argv[]) {

   int arr[6] = {5, 6, 8, 4, 2, 1};

   std::cout << BinarySearch(arr, 6, 84);

   return 0;
}
