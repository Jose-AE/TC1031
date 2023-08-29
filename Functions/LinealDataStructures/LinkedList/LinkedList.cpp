#include "LinkedList.h"

LinkedList::LinkedList() { first = nullptr; }

int& LinkedList::operator[](int index) {

   int counter = 0;
   Node* temp;
   temp = first;

   while (counter < index) {
      counter++;
      temp = temp->getNext();
   }

   return temp->getData();
}

void LinkedList::Append(int data) {}
