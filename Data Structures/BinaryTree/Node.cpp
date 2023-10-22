#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
Node<T>::Node() {}

template <typename T>
Node<T>::Node(T data, Node<T>* leftNodePtr, Node<T>* rightNodePtr)
    : data(data), leftNodePtr(leftNodePtr), rightNodePtr(rightNodePtr) {}

template <typename T>
T Node<T>::getData() {
   return data;
}

template <typename T>
void Node<T>::setData(T data) {
   this->data = data;
}

template <typename T>
Node<T>* Node<T>::getRightNodePtr() {
   return rightNodePtr;
}

template <typename T>
Node<T>* Node<T>::getLeftNodePtr() {
   return leftNodePtr;
}

template <typename T>
void Node<T>::setLeftNodePtr(Node<T>* node) {
   leftNodePtr = node;
}

template <typename T>
void Node<T>::setRightNodePtr(Node<T>* node) {
   rightNodePtr = node;
}

template <typename T>
void Node<T>::Print() {
   cout << "Data: " << data;
   cout << "LeftPtr: " << leftNodePtr;
   cout << "RightPtr: " << rightNodePtr;
}

template <typename T>
int Node<T>::getHeight() {

   // if single node
   if (leftNodePtr == nullptr && rightNodePtr == nullptr) {
      return 0;
   }
   // if there are 2 child nodes (L and R)
   else if (leftNodePtr != nullptr && rightNodePtr != nullptr) {
      return max(leftNodePtr->getHeight(), rightNodePtr->getHeight()) + 1;
   }
   // if only one child node
   else {
      int child_height = (leftNodePtr != nullptr ? leftNodePtr->getHeight()
                                                 : rightNodePtr->getHeight());
      return child_height + 1;
   }
}

template class Node<int>;