#include "Register.h"
#include <sstream>

bool Register::operator<(Register reg) { return reg.getIP() < this->getIP(); }

string Register::getIP() {

   string ip;
   int i = 0;

   istringstream iss(data);
   while (iss >> ip) {
      if (i == 3) break;
      i++;
   }

   return ip;
}

string Register::getData() { return data; }

Register::Register(string data) : data(data) {}
