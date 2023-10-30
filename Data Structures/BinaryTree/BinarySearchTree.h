#pragma once
#include <iostream>
#include "Node.h"

using namespace std;
template <typename T>
class BinarySearchTree {
  protected:
   Node<T>* root = nullptr;

  public:
   BinarySearchTree();
   Node<T>* Insert(T data, Node<T>* tempRoot = nullptr);
   Node<T>* Delete(T data, Node<T>* tempRoot = nullptr);

   Node<T>* getRootPtr();
   Node<T>* getMaxDataNodePtr(Node<T>* startNodePtr = nullptr);
   Node<T>* getMinDataNodePtr(Node<T>* startNodePtr = nullptr);

   void setRootPtr(Node<T>* node);
   void Print(string prefix, Node<T>* node, bool isLeft);
   void Print();
};
