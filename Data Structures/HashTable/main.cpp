#include <iostream>
#include "HashTable.h"

using namespace std;

int main() {
   HashTable<string> hashTable;

   hashTable.insert(10, "hola");
   hashTable.insert(100, "hello");

   cout << hashTable.find(100);

   return 0;
}
