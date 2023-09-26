#pragma once

#include <string>
using namespace std;

class Student {
  private:
   string name;
   string id;
   string major;

  public:
   string getName();
   string getId();
   string getMajor();

   void setName(string name);
   void setId(string id);
   void setMajor(string major);

   Student(string name, string id, string major);

   ~Student();
};

string Student::getName() { return name; }

string Student::getId() { return id; }

string Student::getMajor() { return major; }

void Student::setName(string name) { this->name = name; }

void Student::setId(string id) { this->id = id; }

void Student::setMajor(string major) { this->major = major; }

Student::Student(string name, string id, string major)
    : name(name), id(id), major(major) {}

Student::~Student() {}
