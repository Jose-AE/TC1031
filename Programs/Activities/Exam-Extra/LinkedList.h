#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class LinkedList {

  private:
   Node<T>* firstNodePtr = nullptr;
   Node<T>* lastNodePtr = nullptr;

  public:
   LinkedList();
   Node<T>* getFirstNodePtr();
   Node<T>* getLastNodePtr();

   Node<T>* getNodePtrAtAindex(int index);

   void setFirstNodePtr(Node<T>* nodePtr);
   void setLastNodePtr(Node<T>* nodePtr);

   void append(const T& value);
   void Print();
   int getLength();
   void Swap(int index1, int index2);

   void QuickSort(LinkedList<T> list, int start, int end);
};

template <typename T>
LinkedList<T>::LinkedList() {}

template <typename T>
Node<T>* LinkedList<T>::getFirstNodePtr() {
   return firstNodePtr;
}

template <typename T>
Node<T>* LinkedList<T>::getLastNodePtr() {
   return lastNodePtr;
}

template <typename T>
Node<T>* LinkedList<T>::getNodePtrAtAindex(int index) {
   Node<T>* nextPtr = firstNodePtr;
   for (int i = 0; i < index; i++) {
      nextPtr = nextPtr->getNextNodePtr();
   }
   return nextPtr;
}

template <typename T>
void LinkedList<T>::setFirstNodePtr(Node<T>* nodePtr) {
   firstNodePtr = nodePtr;
}

template <typename T>
void LinkedList<T>::setLastNodePtr(Node<T>* nodePtr) {
   lastNodePtr = nodePtr;
}

template <typename T>
void LinkedList<T>::append(const T& value) {
   Node<T>* newNode = new Node<T>(value, lastNodePtr, nullptr);
   if (lastNodePtr == nullptr) {
      firstNodePtr = newNode;
      lastNodePtr = newNode;
   } else {
      lastNodePtr->setNextNodePtr(newNode);
      lastNodePtr = newNode;
   }
}

template <typename T>
void LinkedList<T>::Print() {
   Node<T>* nextPtr = firstNodePtr;

   while (nextPtr != nullptr) {
      cout << nextPtr->getData() << endl;

      nextPtr = nextPtr->getNextNodePtr();
   }
}

template <typename T>
int LinkedList<T>::getLength() {
   Node<T>* nextPtr = firstNodePtr;

   int length = 0;
   while (nextPtr != nullptr) {
      length++;
      nextPtr = nextPtr->getNextNodePtr();
   }

   return length;
}

template <typename T>
void LinkedList<T>::Swap(int index1, int index2) {
   T temp = this->getNodePtrAtAindex(index1)->getData();

   getNodePtrAtAindex(index1)->setData(getNodePtrAtAindex(index2)->getData());
   getNodePtrAtAindex(index2)->setData(temp);
}

template <typename T>
void LinkedList<T>::QuickSort(LinkedList<T> list, int start, int end) {
   if (end <= start) return;

   T pivot = list.getNodePtrAtAindex(end)->getData();
   int i = start - 1;

   for (int j = start; j < end; j++) {
      if (list.getNodePtrAtAindex(j)->getData() < pivot) {
         i++;
         list.Swap(i, j);
      }
   }
   i++;
   list.Swap(end, i);

   QuickSort(list, start, i - 1);
   QuickSort(list, i + 1, end);
}
