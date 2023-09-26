#include "Queue.h"
#include <iostream>

template <typename T>
Queue<T>::Queue(){
    first = nullptr;
}
template <typename T>
void Queue<T>::enque(Node<T> *node){
    if(first==nullptr){
        first=node;
    }else{
        Node<T> *temp=first;
        while(temp->getNext()!=nullptr){
            temp=temp->getNext();
        }
        temp->setNext(node);
    }

}

template <typename T>
void Queue<T>::print(){
    if(first==nullptr){
        cout<<"Empty Stack"<<endl;
    }
    else{
        Node<T> *temp = first;
        while(temp!=nullptr){
            cout<<temp->getData()<<endl;
            temp = temp->getNext();
        }
    }
}

template <typename T>
void Queue<T>::deque(){
    if(first==nullptr){
        cout<<"Empty Stack"<<endl;
    }
    else{
        first=first->getNext();
    }

}
template <typename T>
Node<T>* Queue<T>::first(){
    return first;
}

template class Queue<int>;