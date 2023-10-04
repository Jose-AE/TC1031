#pragma once
#include "LinkedList.h"
#include "Ticket.h"

class Queue {
  private:
   LinkedList<Ticket> list;

  public:
   Queue();
   void enque(Ticket ticket);
   Ticket deque();
   void Print();
};
