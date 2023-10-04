#pragma once

template <typename T>
class Node {
  private:
   T data;
   Node<T>* nextNodePtr;
   Node<T>* prevNodePtr;

  public:
   Node(T data, Node<T>* nextNodePtr, Node<T>* prevNodePtr);
   Node<T>* getNextNodePtr();
   Node<T>* getPrevNodePtr();
   T getData();
   void setNextNodePtr(Node<T>* nextNode);
   void setPrevNodePtr(Node<T>* prevNode);
   void setData(T data);
};

template <typename T>
Node<T>::Node(T data, Node<T>* prevNodePtr, Node<T>* nextNodePtr)
    : data(data), prevNodePtr(prevNodePtr), nextNodePtr(nextNodePtr) {}

template <typename T>
Node<T>* Node<T>::getNextNodePtr() {
   return nextNodePtr;
}

template <typename T>
Node<T>* Node<T>::getPrevNodePtr() {
   return prevNodePtr;
}

template <typename T>
T Node<T>::getData() {
   return data;
}

template <typename T>
void Node<T>::setNextNodePtr(Node<T>* nextNode) {
   nextNodePtr = nextNode;
}

template <typename T>
void Node<T>::setPrevNodePtr(Node<T>* prevNode) {
   prevNodePtr = prevNode;
}

template <typename T>
void Node<T>::setData(T data) {
   this->data = data;
}
