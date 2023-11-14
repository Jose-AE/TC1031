#include "User.h"

User::User(string name) : name(name) {}

User::User() { name = ""; }

string User::getName() { return name; }

bool User::operator==(const User& user) { return this->name == user.name; }

bool User::operator!=(const User& user) { return this->name != user.name; }

std::ostream& operator<<(std::ostream& os, const User& user) {
   os << "" << user.name << "";
   return os;
}