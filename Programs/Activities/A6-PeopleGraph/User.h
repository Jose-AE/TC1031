#include <iostream>

using namespace std;

class User {
  private:
   string name;

  public:
   User(string name);
   User();

   string getName();

   bool operator==(const User& user);
   bool operator!=(const User& user);

   friend ostream& operator<<(ostream& os, const User& user);
};
