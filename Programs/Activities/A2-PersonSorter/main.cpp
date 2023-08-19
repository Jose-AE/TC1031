#include <iostream>
#include "../../../Functions/Utils/PrintArray.h"
#include "./PersonSorter.h"
#include "Person.h"

using namespace std;
int main() {
   Person persons[] = {Person("Joe", 56), Person("Albert", 21),
                       Person("Charles", 15), Person("Mike", 18)};

   cout << "------------Unsorted-------------\n";
   PrintArray(persons, 4);
   PersonSorter(persons, 4);
   cout << "------------Sorted-------------\n";
   PrintArray(persons, 4);

   return 0;
}
