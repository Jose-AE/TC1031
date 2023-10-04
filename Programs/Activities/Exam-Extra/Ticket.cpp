#include "Ticket.h"

Ticket::Ticket(int num, string desc, int prio)
    : num(num), desc(desc), prio(prio) {}

ostream& operator<<(ostream& os, const Ticket& ticket) {

   os << "Num: " << ticket.num << " Desc: " << ticket.desc;
   return os;
}
