// Dado un arreglo de números de 10 elementos, encontrar el valor más pequeño y
// más grande

#include <iostream>

using namespace std;

int main() {

   int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

   int min = arr[0];
   int max = arr[0];

   for (int i : arr) {
      if (i > max) max = i;
      if (i < min) min = i;
   }

   cout << "min: " << min << endl;
   cout << "max: " << max << endl;

   return 0;
}
