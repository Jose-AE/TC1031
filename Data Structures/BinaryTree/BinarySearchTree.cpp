
#include "BinarySearchTree.h"
#include <queue>

template <typename T>
inline BinarySearchTree<T>::BinarySearchTree() {}

/**
 * @brief Inserts a node with the given data into the tree
 * @param data Data to be inserted
 * @param tempRoot Parent root used for recursion (default = tree.root)
 * @return Pointer to the Node that was created to insert data
 */
template <typename T>
Node<T>* BinarySearchTree<T>::Insert(T data, Node<T>* tempRoot) {
   Node<T>* newNode;

   if (this->root == nullptr) {
      newNode = new Node<T>(data, nullptr, false);
      this->root = newNode;
   }
   if (tempRoot == nullptr) {
      tempRoot = this->root;
   };

   // if should send left
   if (data < tempRoot->getData()) {

      if (tempRoot->getLeftNodePtr() != nullptr) {
         // recurse left
         return Insert(data, tempRoot->getLeftNodePtr());
      } else {
         // insert left
         newNode = new Node<T>(data, tempRoot, true);
         tempRoot->setLeftNodePtr(newNode);
      }
   }

   // if should send right
   if (data > tempRoot->getData()) {

      if (tempRoot->getRightNodePtr() != nullptr) {
         // recurse right
         return Insert(data, tempRoot->getRightNodePtr());
      } else {
         // insert rigth
         newNode = new Node<T>(data, tempRoot, false);
         tempRoot->setRightNodePtr(newNode);
      }
   }

   return newNode;
}

template <typename T>
Node<T>* BinarySearchTree<T>::getRootPtr() {
   return root;
}

template <typename T>
void BinarySearchTree<T>::setRootPtr(Node<T>* node) {
   root = node;
}

template <typename T>
void BinarySearchTree<T>::Print(string prefix, Node<T>* node, bool isLeft) {
   if (node != nullptr) {
      cout << prefix;

      cout << (isLeft ? "|--[" : "|--[");  // └──

      // print the value of the node
      cout << node->getData() << std::endl;

      // enter the next tree level - left and right branch
      Print(prefix + (isLeft ? "|   " : "    "), node->getLeftNodePtr(), true);
      Print(prefix + (isLeft ? "|   " : "    "), node->getRightNodePtr(),
            false);
   }
}

template <typename T>
void BinarySearchTree<T>::Print() {
   cout << "\n[Height: " << root->getHeight() << "]";
   cout << "\n[Root BF: " << root->getBalanceFactor() << "]\n\n";

   cout << "Tree diagram: \n";
   Print("", root, false);
}

// Templates
template class BinarySearchTree<int>;