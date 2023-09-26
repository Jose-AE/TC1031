#include <iostream>

int maisn() {
   int var1 = 42;
   int& test1 = var1;

   int var2 = 42;
   int* test2 = &var2;

   std::cout << &test1 << ", " << &var1 << std::endl;

   return 0;
}
