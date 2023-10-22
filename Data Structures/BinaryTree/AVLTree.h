#pragma once
#include "BinarySearchTree.h"

template <typename T>
class AVLTree : public BinarySearchTree<T> {
  private:
   /* data */
  public:
   AVLTree(/* args */);
   void Insert(T data);
};
