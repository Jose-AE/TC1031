#include "Node.h"

template <typename T>
Node<T>::Node() {}

template <typename T>
Node<T>::Node(T data, Node<T>* leftNodePtr = nullptr,
              Node<T>* rightNodePtr = nullptr)
    : data(data), leftNodePtr(leftNodePtr), rightNodePtr(rightNodePtr) {}

template <typename T>
T Node<T>::getData() {
   return data;
}

template <typename T>
Node<T>* Node<T>::getRightNodePtr() {
   return rightNodePtr;
}

template <typename T>
Node<T>* Node<T>::getLeftNodePtr() {
   return leftNodePtr;
}

template class Node<int>;