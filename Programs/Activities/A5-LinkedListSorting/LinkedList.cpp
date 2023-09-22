#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : first(nullptr) {}

void LinkedList::setFirst(Node* first) { this->first = first; }

Node* LinkedList::getFirst() { return first; }

void LinkedList::print() {
   cout << "Printing linked list" << endl;
   if (first == nullptr) {
      cout << "Empty list" << endl;
   } else {
      Node* temp;
      temp = first;
      while (temp != nullptr) {
         cout << temp->getData() << ",";
         temp = temp->getNext();
      }
      cout << endl;
   }
}

void LinkedList::addNode(Node* node) {
   if (first == nullptr) {
      first = node;
   } else {
      Node* temp = first;
      while (temp->getNext() != nullptr) {
         temp = temp->getNext();
      }
      temp->setNext(node);
   }
}
void LinkedList::addNodeFirst(Node* node) {
   if (first == nullptr) {
      first = node;
   } else {
      Node* temp = first;
      node->setNext(temp);
      first = node;
   }
}

void LinkedList::addAtPos(Node* node, int pos) {
   if (pos == 0) {
      Node* temp = first;
      node->setNext(temp);
      first = node;
   } else {
      Node* temp = first;
      int i = 0;
      while ((temp->getNext() != nullptr) && i < pos - 1) {
         temp = temp->getNext();
         i++;
      }
      node->setNext(temp->getNext());
      temp->setNext(node);
   }
}

Node* LinkedList::merge(Node* left, Node* right) {
   if (!left) return right;
   if (!right) return left;

   if (left->getData() < right->getData()) {
      left->setNext(merge(left->getNext(), right));
      return left;
   } else {
      right->setNext(merge(left, right->getNext()));
      return right;
   }
}

void LinkedList::mergeSort() {
   if (!first || !first->getNext()) {
      return;
   }

   Node* mid = split(first);
   LinkedList left;
   left.setFirst(first);
   LinkedList right;
   right.setFirst(mid);

   left.mergeSort();
   right.mergeSort();

   first = merge(left.getFirst(), right.getFirst());
}

Node* LinkedList::split(Node* head) {
   Node* fast = head;
   Node* slow = head;

   while (fast->getNext() && fast->getNext()->getNext()) {
      fast = fast->getNext()->getNext();
      slow = slow->getNext();
   }

   Node* mid = slow->getNext();
   slow->setNext(nullptr);
   return mid;
}

void LinkedList::bubbleSort() {
   if (!first || !first->getNext()) {
      return;
   }

   bool swapped;
   Node* current;
   Node* lastSorted = nullptr;

   do {
      swapped = false;
      current = first;

      while (current->getNext() != lastSorted) {
         if (current->getData() > current->getNext()->getData()) {
            swapNodes(current, current->getNext());
            swapped = true;
         }
         current = current->getNext();
      }
      lastSorted = current;
   } while (swapped);
}

void LinkedList::insertionSort() {
   if (!first || !first->getNext()) {
      return;
   }

   LinkedList sortedList;
   Node* current = first;

   while (current) {
      Node* next = current->getNext();
      sortedList.insertSorted(current);
      current = next;
   }

   first = sortedList.getFirst();
}

void LinkedList::insertSorted(Node* newNode) {
   if (!first || first->getData() >= newNode->getData()) {
      newNode->setNext(first);
      first = newNode;
   } else {
      Node* current = first;
      while (current->getNext() &&
             current->getNext()->getData() < newNode->getData()) {
         current = current->getNext();
      }
      newNode->setNext(current->getNext());
      current->setNext(newNode);
   }
}

void LinkedList::selectionSort() {
   if (!first || !first->getNext()) {
      return;
   }

   Node* current = first;
   while (current) {
      Node* minNode = findMin(current);
      swapNodes(current, minNode);
      current = current->getNext();
   }
}

Node* LinkedList::findMin(Node* start) {
   Node* minNode = start;
   Node* current = start->getNext();

   while (current) {
      if (current->getData() < minNode->getData()) {
         minNode = current;
      }
      current = current->getNext();
   }

   return minNode;
}

void LinkedList::swapNodes(Node* node1, Node* node2) {
   int tempData = node1->getData();
   node1->setData(node2->getData());
   node2->setData(tempData);
}
