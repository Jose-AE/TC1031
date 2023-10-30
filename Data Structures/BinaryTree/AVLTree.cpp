#include "AVLTree.h"

template <typename T>
void AVLTree<T>::Balance(Node<T>* parentRoot) {
   //---check what rot to do
   int bf = parentRoot->getBalanceFactor();
   Node<T>* rootLeftNodePtr = parentRoot->getLeftNodePtr();
   Node<T>* rootRightNodePtr = parentRoot->getRightNodePtr();

   if (rootRightNodePtr != nullptr) {

      if (bf < -1 && rootRightNodePtr->getBalanceFactor() <= -1) {
         // leeft rot
         cout << "[left rot to node with data: " << parentRoot->getData() << "]"
              << endl;

         if (parentRoot->getParentNodePtr() != nullptr) {

            if (parentRoot->isLeftChildNode()) {
               parentRoot->getParentNodePtr()->setLeftNodePtr(
                   leftRotate(parentRoot));
            } else {

               parentRoot->getParentNodePtr()->setRightNodePtr(
                   leftRotate(parentRoot));
            }
         } else {
            // if its rotating the root node
            this->root = leftRotate(this->root);
         }
      }

      /*
           if   root.bf < -1  and root.right.bf == 1
           --Right left rot
      */

      if (bf < -1 && rootRightNodePtr->getBalanceFactor() >= 1) {
         // Right left rot
         cout << "[Right left rot to node with data: " << parentRoot->getData()
              << "]";  // 1

         parentRoot->setRightNodePtr(rightRotate(rootRightNodePtr));

         cout << "Node par:" << parentRoot->getParentNodePtr() << "/*/*/";  // 0

         if (parentRoot->getParentNodePtr() != nullptr) {

            if (parentRoot->isLeftChildNode()) {
               parentRoot->getParentNodePtr()->setLeftNodePtr(
                   leftRotate(parentRoot));
            } else {
               parentRoot->getParentNodePtr()->setRightNodePtr(
                   leftRotate(parentRoot));
            }
         }

         else {
            cout << "/////Break/////";
            //  If it's rotating the root node
            this->root = leftRotate(parentRoot);
         }
      }
   }

   if (rootLeftNodePtr != nullptr) {  // if there is right node
      /*
      if root.bf > 1 and root.left.bf == 1
      --right rot
      */

      if (bf > 1 && rootLeftNodePtr->getBalanceFactor() >= 1) {
         // right rot
         // this->root = rightRotate(this->root);
         cout << "[Right rot]" << endl;

         if (parentRoot->getParentNodePtr() != nullptr) {

            if (parentRoot->isLeftChildNode()) {
               parentRoot->getParentNodePtr()->setLeftNodePtr(
                   rightRotate(parentRoot));
            } else {
               parentRoot->getParentNodePtr()->setRightNodePtr(
                   rightRotate(parentRoot));
            }
         } else {
            // if its rotating the root node
            this->root = rightRotate(this->root);
         }
      }

      /*
         if root.bf > 1 and root.left.bf == -1
         --left right rot
      */

      if (bf > 1 && rootLeftNodePtr->getBalanceFactor() <= -1) {
         // left right rot
         cout << "[left right rot]" << endl;

         parentRoot->setLeftNodePtr(leftRotate(rootLeftNodePtr));
         // Now, perform the right rotation on the root
         if (parentRoot->getParentNodePtr() != nullptr) {
            if (parentRoot->isLeftChildNode()) {
               parentRoot->getParentNodePtr()->setLeftNodePtr(
                   rightRotate(parentRoot));
            } else {
               parentRoot->getParentNodePtr()->setRightNodePtr(
                   rightRotate(parentRoot));
            }
         } else {
            // If it's rotating the root node
            this->root = rightRotate(parentRoot);
         }
      }
   }
}

template <typename T>
AVLTree<T>::AVLTree() {}

template <typename T>
void AVLTree<T>::Insert(T data) {
   Node<T>* insertedNode = BinarySearchTree<T>::Insert(data);

   cout << "\n\n-----inserted: " << data << "--------" << endl;
   cout << "Inserted node parent: " << insertedNode->getParentNodePtr() << endl;

   if (insertedNode == nullptr) {
      return;
   }

   // Go from bottom to top and balance each node
   while (insertedNode->getParentNodePtr() != nullptr) {
      insertedNode = insertedNode->getParentNodePtr();

      // error-flag   prints 34 and then 1 and then again 34 foreverr
      cout << insertedNode->getData() << endl;

      Balance(insertedNode);
   }

   this->Print();
}

template <typename T>
void AVLTree<T>::Delete(T data) {
   Node<T>* deletedNodeChildPtr = BinarySearchTree<T>::Delete(data);

   cout << "\n\n-----Deleted: " << data << "--------" << endl;

   if (deletedNodeChildPtr == nullptr) {
      return;
   }

   // Go from bottom to top and balance each node
   while (deletedNodeChildPtr->getParentNodePtr() != nullptr) {
      deletedNodeChildPtr = deletedNodeChildPtr->getParentNodePtr();
      Balance(deletedNodeChildPtr);
   }

   this->Print();
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
