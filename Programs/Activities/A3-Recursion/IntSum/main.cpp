#include <iostream>

using namespace std;

int SumRecursive(int n) {
   if (n == 1)
      return 1;
   else
      return n + SumRecursive(n - 1);
}

int SumIterative(int n) {
   int counter;
   for (int i = 1; i < n + 1; i++) {
      counter += i;
   }
   return counter;
}

int main(int argc, char const *argv[]) {

   cout << SumRecursive(10) << endl;
   cout << SumIterative(10) << endl;

   return 0;
}
