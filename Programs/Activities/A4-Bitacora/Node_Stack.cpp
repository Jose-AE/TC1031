#include "Node_Stack.h"
#include <iostream>
template <typename T>
Node_Stack<T>::Node_Stack(T value) {
   this->data = value;
   this->next = nullptr;
}

template <typename T>
T Node_Stack<T>::getData() {
   return data;
}

template <typename T>
void Node_Stack<T>::setData(T value) {
   data = value;
}

template <typename T>
Node_Stack<T>* Node_Stack<T>::getNext() {
   return next;
}

template <typename T>
void Node_Stack<T>::setNext(Node_Stack* node) {
   next = node;
}
template class Node_Stack<int>;
template class Node_Stack<string>;
