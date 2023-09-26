#pragma once

#include <string>

using namespace std;

class Register {
  private:
   // Oct 9 10:32:24 423.2.230.77:6166 Failed password for illegal user guest

   string data;

  public:
   bool operator<(Register reg);

   string getIP();
   string getData();

   Register(string data);
};
