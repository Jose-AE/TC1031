#include "Person.h"
#include <iostream>

using namespace std;

Person::Person() {}
Person::Person(string name, int age) : name(name), age(age) {}
Person::~Person() {}

string Person::getName() const { return name; }
int Person::getAge() const { return age; }

ostream& operator<<(ostream& os, const Person& person) {
   os << "[Name: " << person.getName() << "]-[Age: " << person.getAge() << "]";
   return os;
}