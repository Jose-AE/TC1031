#pragma once

template <typename ArrayType>
void SwitchArrayValues(ArrayType arr[], int index1, int index2) {
   ArrayType temp = arr[index1];
   arr[index1] = arr[index2];
   arr[index2] = temp;
}