#pragma once
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList {
  private:
   Node<T>* first;
   int length = 0;

  public:
   LinkedList();
   T& operator[](int index);

   void Insert(T data, int index = -1);
   int getLength();
   void Switch(int i1, int i2);
};

// implem
template <typename T>
LinkedList<T>::LinkedList() : first(nullptr) {}

template <typename T>
int LinkedList<T>::getLength() {
   return length;
}

template <typename T>
inline void LinkedList<T>::Switch(int i1, int i2) {
   if (i1 > (length - 1) || i2 > (length - 1))
      throw runtime_error("Index is out of range");

   Node<T>* firstNode = first;
   Node<T>* secondtNode = first;

   for (int i = 0; i < (i1 + 1); i++) {
      firstNode = firstNode->getNext();
   }

   for (int i = 0; i < (i2 + 1); i++) {
      secondtNode = secondtNode->getNext();
   }

   T temp = firstNode->getData();

   firstNode->setData(secondtNode->getData());
   secondtNode->setData(temp);
}

template <typename T>
void LinkedList<T>::Insert(T data, int index) {
   if (first == nullptr) first = new Node<T>(data, nullptr);

   Node<T>* currentNode = first;

   if (index == -1) {
      while (currentNode->getNext() != nullptr) {
         currentNode = currentNode->getNext();
      }
      currentNode->setNext(new Node<T>(data));
   } else if (index == 0) {
      first = new Node<T>(data, first);
   } else if (index < (length)) {
      for (int i = 1; i < index; i++) {
         currentNode = currentNode->getNext();
      }
      currentNode->setNext(new Node<T>(data, currentNode->getNext()));
   } else {
      throw runtime_error("Index is out of range");
   }

   length++;
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
   if (index > (length - 1)) throw runtime_error("Index is out of range");

   Node<T>* currentNode = first;

   if (index == -1) {
      while (currentNode->getNext() != nullptr) {
         currentNode = currentNode->getNext();
      }
      return currentNode->getData();

   } else {
      for (int i = 0; i < index + 1; i++) {
         // cout << "-----";
         currentNode = currentNode->getNext();
      }

      return currentNode->getData();
   }
}
