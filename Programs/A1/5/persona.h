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
   Persona(int age, string name);
   ~Persona();
};
