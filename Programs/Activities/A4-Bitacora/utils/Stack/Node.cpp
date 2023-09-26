#include "Node.h"
#include <iostream>
template <typename T>
Node<T>::Node(T value) {
    this->data=value;
    this->next=nullptr;
}

template <typename T>
T Node<T>::getData() {
    return data;
}

template <typename T>
void Node<T>::setData(T value) {
    data = value;
}

template <typename T>
Node<T>* Node<T>::getNext() {
    return next;
}

template <typename T>
void Node<T>::setNext(Node* node) {
    next = node;
}
template class Node<int>;
