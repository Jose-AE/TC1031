#include <iostream>

using namespace std;

int FibonacciRecursive(int n) {
   if (n <= 0) return 0;
   if (n == 1) return 1;

   return FibonacciRecursive(n - 1) + FibonacciRecursive(n - 2);
}

int FibonacciIterative(int n) {
   if (n <= 0) return 0;
   if (n == 1) return 1;

   int prev = 0;
   int current = 1;

   for (int i = 2; i <= n; ++i) {
      int next = prev + current;
      prev = current;
      current = next;
   }

   return current;
}

int main(int argc, char const *argv[]) {

   cout << FibonacciRecursive(8) << endl;
   cout << FibonacciIterative(8) << endl;

   return 0;
}
