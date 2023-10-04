#include "Stack.h"
#include "Node.h"

Stack::Stack() {}

void Stack::push(Ticket ticket) {
   Node<Ticket>* temp = list.getFirstNodePtr();

   if (list.getFirstNodePtr() == nullptr) {

      list.setFirstNodePtr(new Node<Ticket>(ticket, nullptr, temp));

      // cout << "added first node\n";
   } else {

      list.setFirstNodePtr(new Node<Ticket>(ticket, temp, nullptr));
      // cout << "added edxtra node\n";
   }
}

Ticket Stack::pop() {
   Node<Ticket>* temp = list.getFirstNodePtr();
   if (list.getFirstNodePtr()->getPrevNodePtr() != nullptr) {
      list.setFirstNodePtr(list.getFirstNodePtr()->getPrevNodePtr());
      return temp->getData();
   } else {
      list.setFirstNodePtr(nullptr);
      return temp->getData();
   }
}

void Stack::Print() {
   Node<Ticket>* nextPtr = list.getFirstNodePtr();

   while (nextPtr != nullptr) {
      cout << nextPtr->getData() << endl;

      nextPtr = nextPtr->getPrevNodePtr();
   }
}
