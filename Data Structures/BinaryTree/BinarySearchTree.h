#pragma once
#include <iostream>
#include "Node.h"

using namespace std;
template <typename T>
class BinarySearchTree {
  private:
   Node<T>* root;

  public:
   BinarySearchTree();
   void Insert(T data, Node<T>* tempRoot = nullptr);
   Node<T>* getRootPtr();
   void Print(Node<T>* tempRoot = nullptr);
};
