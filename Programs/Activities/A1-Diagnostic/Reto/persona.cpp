#include "persona.h"
#include <iostream>

Persona::Persona(int age, string name) : age(age), name(name) {}

Persona::~Persona() {}

void Persona::PrintPerson() {
   cout << "age: " << age << endl;
   cout << "name: " << name << endl;
};
void Persona::agePerson() {
   cout << "Happe birthday" << endl;
   age++;
};

int Persona::GetAge() { return age; };