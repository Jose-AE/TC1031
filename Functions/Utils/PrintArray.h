#pragma once

#include <iostream>

using namespace std;

template <typename ArrayType>
void PrintArray(ArrayType arr[], int size) {

   for (int i = 0; i < size; i++) {
      cout << arr[i] << endl;
   }
}