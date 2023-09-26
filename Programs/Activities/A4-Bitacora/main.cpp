#include <fstream>
#include <iostream>
#include <stack>
#include "./utils/ReadSortTXT.h"
int main(int argc, char const *argv[]) {

   ReadSortTXT();

   fstream newfile;
   stack<Register> stack;

   newfile.open("data/bitacora.txt", ios::in);
   if (newfile.is_open()) {
      string line;
      while (getline(newfile, line)) {
         stack.push(Register(line));  // insert register instead of string
      }
      newfile.close();
   }

   newfile.open("data/bitacora.txt", ios::in);
   if (newfile.is_open()) {
      string line;
      while (getline(newfile, line)) {
         stack.push(Register(line));  // insert register instead of string
      }
      newfile.close();
   }

   return 0;
}
