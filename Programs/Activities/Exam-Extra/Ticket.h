#pragma once
#include <iostream>

using namespace std;

class Ticket {
  private:
   int num;
   string desc;
   int prio;

  public:
   Ticket(int num, string desc, int prio);
   bool operator<(const Ticket& t) { return num < t.num; };

   friend ostream& operator<<(ostream& os, const Ticket& ticket);
};
