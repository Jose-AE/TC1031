
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
      newNode = new Node<T>(data);
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
         newNode = new Node<T>(data);
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
         newNode = new Node<T>(data);
         tempRoot->setRightNodePtr(newNode);
      }
   }

   return newNode;
}

template <typename T>
Node<T>* BinarySearchTree<T>::Delete(T data, Node<T>* tempRoot) {
   // for first time calling function from outside
   if (tempRoot == nullptr) {
      tempRoot = this->root;
   };

   // if tree is empty return
   if (this->root == nullptr) {
      return nullptr;
   }

   // if on a leaf and no data was found break
   if (tempRoot->getLeftNodePtr() == nullptr &&
       tempRoot->getRightNodePtr() == nullptr && tempRoot->getData() != data) {
      return nullptr;
   }

   // if temp root has data delete temproot and subtitute it
   if (tempRoot->getData() == data) {

      Node<T>* deletedNodeParentPtr = tempRoot->getParentNodePtr();  // 34

      // if leaf node
      if (tempRoot->getRightNodePtr() == nullptr &&
          tempRoot->getLeftNodePtr() == nullptr) {

         // if root of tree
         if (tempRoot->getParentNodePtr() == nullptr) {
            delete tempRoot;
            this->root = nullptr;
         } else {
            if (tempRoot->isLeftChildNode())
               tempRoot->getParentNodePtr()->setLeftNodePtr(nullptr);
            else
               tempRoot->getParentNodePtr()->setRightNodePtr(nullptr);

            delete tempRoot;
         }

      }
      // when it  has 2 childs
      else if (tempRoot->getRightNodePtr() != nullptr &&
               tempRoot->getLeftNodePtr() != nullptr) {

         Node<T>* maxNodePtrInTempRoot =
             getMaxDataNodePtr(tempRoot->getLeftNodePtr());

         cout << maxNodePtrInTempRoot->getData() << "*/*/*/*";  // 10

         tempRoot->setData(maxNodePtrInTempRoot->getData());

         // delete leaf
         Node<T>* tempParentNode = maxNodePtrInTempRoot->getParentNodePtr();

         if (maxNodePtrInTempRoot->isLeftChildNode())
            tempParentNode->setLeftNodePtr(nullptr);
         else
            tempParentNode->setRightNodePtr(nullptr);

         delete maxNodePtrInTempRoot;

         return tempParentNode;

      }
      // when node to delete has only  1 child
      else {
         Node<T>* deletedNodeParentPtr = tempRoot->getParentNodePtr();

         // if its a right child
         if (tempRoot->getRightNodePtr() != nullptr) {

            if (tempRoot->isLeftChildNode())
               deletedNodeParentPtr->setLeftNodePtr(
                   tempRoot->getRightNodePtr());
            else
               deletedNodeParentPtr->setRightNodePtr(
                   tempRoot->getRightNodePtr());

            delete tempRoot;
            return deletedNodeParentPtr->getLeftNodePtr();
         }
         // if left child
         else {
            if (tempRoot->isLeftChildNode())
               deletedNodeParentPtr->setLeftNodePtr(tempRoot->getLeftNodePtr());
            else
               deletedNodeParentPtr->setRightNodePtr(
                   tempRoot->getLeftNodePtr());

            delete tempRoot;
            return deletedNodeParentPtr->getLeftNodePtr();
         }
      }
   }

   // if should send left
   if (data < tempRoot->getData() && tempRoot->getLeftNodePtr() != nullptr) {
      return Delete(data, tempRoot->getLeftNodePtr());
   }

   // if should send right
   if (data > tempRoot->getData() && tempRoot->getRightNodePtr() != nullptr) {
      return Delete(data, tempRoot->getRightNodePtr());
   }

   // in case it somehow reaches this point, return to break
   return nullptr;
}

template <typename T>
Node<T>* BinarySearchTree<T>::getRootPtr() {
   return root;
}

template <typename T>
Node<T>* BinarySearchTree<T>::getMinDataNodePtr(Node<T>* startNodePtr) {
   if (startNodePtr == nullptr) {
      startNodePtr = this->root;
   }

   if (startNodePtr->getLeftNodePtr() != nullptr) {
      return getMinDataNodePtr(startNodePtr->getLeftNodePtr());
   } else {
      return startNodePtr;
   }
}

template <typename T>
Node<T>* BinarySearchTree<T>::getMaxDataNodePtr(Node<T>* startNodePtr) {
   if (startNodePtr == nullptr) {
      startNodePtr = this->root;
   }

   if (startNodePtr->getRightNodePtr() != nullptr) {
      return getMaxDataNodePtr(startNodePtr->getRightNodePtr());
   } else {
      return startNodePtr;
   }
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