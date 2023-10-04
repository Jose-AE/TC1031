#include "Queue.h"

Queue::Queue() {}

void Queue::enque(Ticket ticket) {
   Node<Ticket>* newNode = new Node<Ticket>(ticket, nullptr, nullptr);

   if (list.getLastNodePtr() == nullptr) {
      list.setFirstNodePtr(newNode);
      list.setLastNodePtr(newNode);
   } else {

      list.getLastNodePtr()->setNextNodePtr(newNode);
      newNode->setPrevNodePtr(list.getLastNodePtr());
      list.setLastNodePtr(newNode);
   }
}

Ticket Queue::deque() {
   if (list.getFirstNodePtr() == nullptr) {
      return Ticket(0, "", 0);
   } else {
      Node<Ticket>* temp = list.getFirstNodePtr();

      list.setFirstNodePtr(temp->getNextNodePtr());

      if (list.getFirstNodePtr() == nullptr) list.setLastNodePtr(nullptr);

      return temp->getData();
   }
}

void Queue::Print() {
   Node<Ticket>* nextPtr = list.getFirstNodePtr();

   while (nextPtr != nullptr) {
      cout << nextPtr->getData() << endl;

      nextPtr = nextPtr->getNextNodePtr();
   }
}
