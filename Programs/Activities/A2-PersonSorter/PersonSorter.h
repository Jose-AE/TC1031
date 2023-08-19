#pragma once

#include "../../../Functions/Utils/SwitchArrayValues.h"
#include "Person.h"

void PersonSorter(Person persons[], int size) {
   for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
         if (persons[j].getAge() > persons[i].getAge())
            SwitchArrayValues(persons, i, j);
      }
   }
}
