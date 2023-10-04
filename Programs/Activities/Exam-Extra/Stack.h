#pragma once
#include "LinkedList.h"
#include "Ticket.h"

class Stack {
  private:
   LinkedList<Ticket> list;

  public:
   Stack();
   void push(Ticket ticket);
   Ticket pop();
   void Print();
};
