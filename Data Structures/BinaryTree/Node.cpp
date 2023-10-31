#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
Node<T>::Node() {}

/**
 * @brief
 * @param data
 * @param parentNodePtr
 * @param leftChildNode is it a left child?
 * @param leftNodePtr = nullptr
 * @param rightNodePtr = nullptr
 */
template <typename T>
Node<T>::Node(T data, Node<T>* leftNodePtr, Node<T>* rightNodePtr)
    : data(data), leftNodePtr(leftNodePtr), rightNodePtr(rightNodePtr) {

   if (leftNodePtr != nullptr) {
      leftNodePtr->setParentNodePtr(this);
   }

   if (rightNodePtr != nullptr) {
      rightNodePtr->setParentNodePtr(this);
   }
}

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
Node<T>* Node<T>::getParentNodePtr() {
   return parentNodePtr;
}

template <typename T>
void Node<T>::setLeftNodePtr(Node<T>* node) {
   leftNodePtr = node;
   if (leftNodePtr != nullptr) {
      leftNodePtr->setParentNodePtr(this);
   }
}

template <typename T>
void Node<T>::setRightNodePtr(Node<T>* node) {
   rightNodePtr = node;
   if (rightNodePtr != nullptr) {
      rightNodePtr->setParentNodePtr(this);  // Corrected this line
   }
}

template <typename T>
void Node<T>::setParentNodePtr(Node<T>* node) {
   parentNodePtr = node;
}

template <typename T>
void Node<T>::Print() {
   cout << "Data: " << data << endl;

   cout << (isLeftChildNode() == 1 ? "Left Child" : "RightChild") << endl;

   if (leftNodePtr != nullptr) {
      cout << "LeftData: " << leftNodePtr->getData()
           << endl;  // Output the data of the left node
   } else {
      cout << "LeftData: nullptr\n";  // Output that the left node is nullptr
   }

   if (rightNodePtr != nullptr) {
      cout << "RightData: " << rightNodePtr->getData()
           << endl;  // Output the data of the right node
   } else {
      cout << "RightData: nullptr\n";  // Output that the right node is nullptr
   }

   if (parentNodePtr != nullptr) {
      cout << "ParentData: " << parentNodePtr->getData()
           << endl;  // Output the data of the parent node
   } else {
      cout << "ParentData: nullptr\n";  // Output that the parent node is
                                        // nullptr
   }
}

template <typename T>
int Node<T>::getBalanceFactor() {

   int balanceFacor = 0;  // L-R
   if (this->getLeftNodePtr() != nullptr) {

      balanceFacor += this->getLeftNodePtr()->getHeight() + 1;
   }
   if (this->getRightNodePtr() != nullptr) {
      balanceFacor -= this->getRightNodePtr()->getHeight() + 1;
   }

   return balanceFacor;
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

template <typename T>
bool Node<T>::isLeftChildNode() {
   if (this->getParentNodePtr() == nullptr) return false;

   return this->getParentNodePtr()->getData() > this->getData();
}

/// templates
template class Node<int>;