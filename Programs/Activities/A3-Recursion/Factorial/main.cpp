#include <iostream>

using namespace std;

int FactorialRecursive(int n) {
   if (n == 1)
      return 1;
   else
      return n * FactorialRecursive(n - 1);
}

int FactorialIterative(int n) {
   int counter = 1;
   for (int i = 1; i < n + 1; i++) {
      counter *= i;
   }
   return counter;
}

int main(int argc, char const *argv[]) {

   cout << FactorialRecursive(7) << endl;
   cout << FactorialIterative(7) << endl;

   return 0;
}
