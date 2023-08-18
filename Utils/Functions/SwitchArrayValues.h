#pragma once

void SwitchArrayValues(int arr[], int index1, int index2) {
   int temp = arr[index1];
   arr[index1] = arr[index2];
   arr[index2] = temp;
}