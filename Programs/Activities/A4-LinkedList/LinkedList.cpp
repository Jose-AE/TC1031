#include "LinkedList.h"
#include "Persona.h"
#include <iostream>
using namespace std;
template <typename T>
LinkedList<T>::LinkedList() {
    first = nullptr;
}
template <typename T>
void LinkedList<T>::addNode(Node<T> *node){
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
void LinkedList<T>::print(){
    Node<T> *temp=first;
    while(temp!=nullptr){
        temp->print();
        temp=temp->getNext();
    }
    cout<<endl;
}
template <typename T>
int LinkedList<T>::find(T data){
    Node<T> *temp = first;
    int count=0;
    while(temp!=nullptr){
        if(temp->getData()==data){
            break;
        }
        count ++;
        temp=temp->getNext();
    }
    if(temp==nullptr){
        return -1;
    }
    return count;
}

template <typename T>
void LinkedList<T>::swap(int x,int y){
    T temp= findAtPos(x)->getData();
    findAtPos(x)->setData(findAtPos(y)->getData());
    findAtPos(y)->setData(temp);
}
template <typename T>
Node<T>* LinkedList<T>::findAtPos(int pos){
    Node<T> *temp=first;
    int count=0;
    while(temp!=nullptr){
        if(count==pos){
            return temp;
        }
        count++;
        temp=temp->getNext();
    }
    return nullptr;
}
template <typename T>
void LinkedList<T>::bubbleSort(){
    Node<T>* temp1=first;
    while(temp1!=nullptr){
        Node<T>* temp2=first;
        int j=0;
        while(temp2->getNext()!=nullptr){
            if(temp2->getData()>temp2->getNext()->getData()){
                swap(j,j+1);
            }
            j++;
            temp2=temp2->getNext();
        }
        temp1=temp1->getNext();
    }
}

template class LinkedList<int>;
template class LinkedList<Persona>;