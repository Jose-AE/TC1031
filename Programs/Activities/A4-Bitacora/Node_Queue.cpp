#include "Node_Queue.h"
#include <iostream>
template <typename T>
Node_Queue<T>::Node_Queue(T value) {
   this->data = value;
   this->next = nullptr;
}

template <typename T>
T Node_Queue<T>::getData() {
   return data;
}

template <typename T>
void Node_Queue<T>::setData(T value) {
   data = value;
}

template <typename T>
Node_Queue<T>* Node_Queue<T>::getNext() {
   return next;
}

template <typename T>
void Node_Queue<T>::setNext(Node_Queue* node) {
   next = node;
}
template class Node_Queue<int>;
template class Node_Queue<string>;
