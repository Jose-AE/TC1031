#include <iostream>
using namespace std;

int main() {
   int a, *b;

   a = 5;
   b = new int;  // allocate mem for a int in memory and set it to pointer b
   *b = 20;      //  *b = get value where pointer points to

   cout << a << " " << *b << endl;

   ////

   int a = 10;
   int* p;
   int* q;

   p = q = &a;  // "p" y "q" van a apuntar al valor de "a"

   cout << *q << " " << *b << endl;

   /////
   int a = 20;
   int* p;
   p = new int(10);

   p = &a;
   cout << *p << endl;

   delete p;

   return 0;
}