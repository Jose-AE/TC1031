#include "Stack.h"
#include <iostream>

template <typename T>
Stack<T>::Stack() {
   first = nullptr;
}
template <typename T>
void Stack<T>::push(Node<T> *node) {
   if (first == nullptr) {
      first = node;
   } else {
      node->setNext(first);
      first = node;
   }
}

template <typename T>
void Stack<T>::print() {
   if (first == nullptr) {
      cout << "Empty Stack" << endl;
   } else {
      Node<T> *temp = first;
      while (temp != nullptr) {
         cout << temp->getData() << endl;
         temp = temp->getNext();
      }
   }
}

template <typename T>
void Stack<T>::pop() {
   if (first == nullptr) {
      cout << "Empty Stack" << endl;
   } else {
      first = first->getNext();
   }
}
template <typename T>
Node<T> *Stack<T>::top() {
   return first;
}

template class Stack<int>;