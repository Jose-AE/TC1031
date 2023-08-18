#include <iostream>
using namespace std;

#pragma once

class Persona {
  private:
   int age;
   string name;

  public:
   void PrintPerson();
   void agePerson();
   int GetAge();
   Persona(int age, string name);
   ~Persona();
};
