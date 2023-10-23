#pragma once
#include "BinarySearchTree.h"

template <typename T>
class AVLTree : public BinarySearchTree<T> {
  private:
   /* data */

  public:
   void Balance(int lastInsertedData);
   AVLTree(/* args */);
   void Insert(T data);

   Node<T>* leftRotate(Node<T>* node);
   Node<T>* rightRotate(Node<T>* node);
};
