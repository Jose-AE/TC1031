#pragma once

#include <string>

using namespace std;

class Person {
  private:
   int age;
   string name;

  public:
   Person();
   Person(string name, int age);
   ~Person();

   string getName() const;
   int getAge() const;
};

ostream& operator<<(ostream& os, const Person& person);