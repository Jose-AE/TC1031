#include "Node.h"
#include "Persona.h"
#include <iostream>
using namespace std;

template <typename T>
Node<T>::Node(T data) { 
    this->data = data; 
}
template <typename T>
void Node<T>::setData(T data) { 
    this->data = data; 
}
template <typename T>
T Node<T>::getData() { 
    return data; 
}

template <typename T>
Node<T> *Node<T>::getNext() { 
    return next; 
}

template <typename T>
void Node<T>::setNext(Node<T> *next) {
    this->next = next; 
}
template <typename T>
void Node<T>::print() { 
    cout <<"["<< data<<"]"; 
}

template class Node<int>;
template class Node<Persona>;