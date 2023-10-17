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
   void printVisual(Node<T>* root, std::string indent, std::string parent_dir);
   void Insert(T data, Node<T>* tempRoot = nullptr);
   Node<T>* getRootPtr();
   void Print(string prefix, Node<T>* node, bool isLeft);
   void Print();
};
