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

template class Node<int>;