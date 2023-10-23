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
   Node<T>* getRootPtr();
   void setRootPtr(Node<T>* node);
   void Print(string prefix, Node<T>* node, bool isLeft);
   void Print();
};
