#include "Register.h"

bool Register::operator<(Register reg) { return reg.getIP() < this->getIP(); }

string Register::getIP() {

   //     string test = "Aug 28 23:07:49 897.53.984.6:6710 Failed password for
   //     root";

   //    test = "Aug 4  03:18:56 960.96.3.29:5268 Failed password for admin";

   if (data.substr(28, 1) == ":")  // long ip
      return data.substr(15, 13);
   else
      return data.substr(15, 12);
}

string Register::getData() { return data; }

Register::Register(string data) : data(data) {}

/*

998.94.195.38:416
998.88.269.79:521
998.52.253.8:5544
998.3.672.68:5974
998.15.599.29:686
998.14.620.53:502



*/