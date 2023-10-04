#include "Queue.h"

Queue::Queue() {}

void Queue::enque(Ticket ticket) {
   Node<Ticket>* newNode = new Node<Ticket>(ticket, nullptr, nullptr);

   if (list.getLastNodePtr() == nullptr) {
      // If the queue is empty, set both first and last nodes to the new node.
      list.setFirstNodePtr(newNode);
      list.setLastNodePtr(newNode);
   } else {
      // Otherwise, update the next pointer of the last node and set the last
      // node to the new node.
      list.getLastNodePtr()->setNextNodePtr(newNode);
      newNode->setPrevNodePtr(list.getLastNodePtr());
      list.setLastNodePtr(newNode);
   }
}

// void Queue::enque(Ticket ticket) {

//    if (list.getLastNodePtr() == nullptr) {
//       list.setFirstNodePtr(new Node<Ticket>(ticket, nullptr, nullptr));
//       list.setLastNodePtr(new Node<Ticket>(ticket, nullptr, nullptr));
//    } else {
//       list.setLastNodePtr(new Node<Ticket>(ticket, temp, nullptr));
//    }
// }

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
