#include <iostream>

int main() {
   int find = 2;
   int arr[] = {1, 2, 3, 5};

   int index = sizeof(arr) / sizeof(arr[0]) / 2;

   while (true) {
      if (arr[index] == find)
         break;
      else if (arr[index] > find)
         index += index / 2;
      else
         index -= index / 2;
   }

   std::cout << index;

   return 0;
}
