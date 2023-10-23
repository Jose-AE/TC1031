#include "AVLTree.h"

template <typename T>
void AVLTree<T>::Balance(int lastInsertedData) {
   // bf = L-R
   // if bf > 1  right rot
   // if bf < -1  left rot

   //---check what rot to do
   int bf = this->root->getBalanceFactor();
   // cout << "Balance factor: " << bf << endl;

   Node<T>* rootLeftNodePtr = this->root->getLeftNodePtr();
   Node<T>* rootRightNodePtr = this->root->getRightNodePtr();

   if (rootRightNodePtr != nullptr) {

      cout << "-----------------\n";
      cout << "Root BF: " << bf << endl;
      cout << "RightNodePtr BF: " << rootRightNodePtr->getBalanceFactor()
           << endl;

      /*
      if   root.bf < -1  and root.right.bf == -1
      --Left rot
      */

      if (bf < -1 && rootRightNodePtr->getBalanceFactor() == -1) {
         // leeft rot
         cout << "left rot" << endl;
         this->root = leftRotate(this->root);
      }

      /*
           if   root.bf < -1  and root.right.bf == 1
           --Right left rot
      */

      if (bf < -1 && rootRightNodePtr->getBalanceFactor() == 1) {
         // Right left rot
         cout << "Right left rot" << endl;
      }
   }

   if (rootLeftNodePtr != nullptr) {  // if there is right node

      cout << "-----------------\n";
      cout << "Root BF: " << bf << endl;
      cout << "LeftNodePtr BF: " << rootLeftNodePtr->getBalanceFactor() << endl;

      /*
      if root.bf > 1 and root.left.bf == 1
      --right rot
      */

      if (bf > 1 && rootLeftNodePtr->getBalanceFactor() == 1) {
         // right rot
         this->root = rightRotate(this->root);
         cout << "Right rot" << endl;
      }

      /*
         if root.bf > 1 and root.left.bf == -1
         --left right rot
      */

      if (bf > 1 && rootLeftNodePtr->getBalanceFactor() == -1) {
         // left right rot
         cout << "left right rot" << endl;
      }
   }

   cout << "-----------------\n";
}

template <typename T>
AVLTree<T>::AVLTree() {}

template <typename T>
void AVLTree<T>::Insert(T data) {
   // call parent class insert method
   BinarySearchTree<T>::Insert(data);

   Balance(data);
}

/**
 * @brief Rotates the given node to the left (https://i.imgur.com/5PGgbgw.png)
 * @param node Node to rotate (A)
 * @return  New parent Node (B)
 */
template <typename T>
Node<T>* AVLTree<T>::leftRotate(Node<T>* node) {
   Node<T>* B = node->getRightNodePtr();
   Node<T>* Y = B->getLeftNodePtr();

   B->setLeftNodePtr(node);
   node->setRightNodePtr(Y);

   return B;
}

/**
 * @brief Rotates the given node to the right (https://i.imgur.com/AOvWiee.png)
 * @param node Node to rotate (A)
 * @return  New parent Node (B)
 */
template <typename T>
Node<T>* AVLTree<T>::rightRotate(Node<T>* node) {
   Node<T>* B = node->getLeftNodePtr();
   Node<T>* Y = B->getRightNodePtr();

   B->setRightNodePtr(node);
   node->setLeftNodePtr(Y);

   return B;
}

// Templates
template class AVLTree<int>;
