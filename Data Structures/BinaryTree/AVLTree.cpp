#include "AVLTree.h"

template <typename T>
AVLTree<T>::AVLTree() {}

template <typename T>
void AVLTree<T>::Insert(T data) {
   // call parent class insert method
   BinarySearchTree<T>::Insert(data);

   // balance tree
}

// Templates
template class AVLTree<int>;

// null node is  height = -1
// single node is height = 0
