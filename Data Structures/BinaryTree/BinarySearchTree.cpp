
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
      this->setRootPtr(newNode);
   }
   if (tempRoot == nullptr) {
      tempRoot = this->root;
   };

   // dont insert if already on tree
   if (tempRoot->getData() == data) {
      return nullptr;
   }

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

   // if temp root has data delete temproot and subtitute it
   if (tempRoot->getData() == data) {

      Node<T>* nodeToDeleteParentPtr = tempRoot->getParentNodePtr();  // 34

      // if leaf node
      if (tempRoot->getRightNodePtr() == nullptr &&
          tempRoot->getLeftNodePtr() == nullptr) {

         // if root of tree
         if (tempRoot->getParentNodePtr() == nullptr) {
            this->setRootPtr(nullptr);
         } else if (tempRoot->isLeftChildNode()) {
            tempRoot->getParentNodePtr()->setLeftNodePtr(nullptr);
         } else {
            tempRoot->getParentNodePtr()->setRightNodePtr(nullptr);
         }
         delete tempRoot;
         return nodeToDeleteParentPtr;
      }
      // when it  has 2 childs
      else if (tempRoot->getRightNodePtr() != nullptr &&
               tempRoot->getLeftNodePtr() != nullptr) {

         Node<T>* maxNodePtrInTempRoot =
             getMaxDataNodePtr(tempRoot->getLeftNodePtr());  // 95

         // cout << "max: " << maxNodePtrInTempRoot->getData() << endl;

         // delete leaf
         Node<T>* tempParentNode = maxNodePtrInTempRoot->getParentNodePtr();

         if (maxNodePtrInTempRoot->isLeftChildNode())
            tempParentNode->setLeftNodePtr(nullptr);
         else
            tempParentNode->setRightNodePtr(nullptr);

         // Switch values and delete
         tempRoot->setData(maxNodePtrInTempRoot->getData());
         delete maxNodePtrInTempRoot;

         // maxNodePtrInTempRoot->Print();

         return getMaxDataNodePtr(tempParentNode);

      }
      // when node to delete has only  1 child
      else {
         // if its a right child
         if (tempRoot->getRightNodePtr() != nullptr) {

            if (tempRoot->isLeftChildNode())
               nodeToDeleteParentPtr->setLeftNodePtr(
                   tempRoot->getRightNodePtr());
            else
               nodeToDeleteParentPtr->setRightNodePtr(
                   tempRoot->getRightNodePtr());

            delete tempRoot;
            return nodeToDeleteParentPtr->getRightNodePtr();
         }
         // if left child
         else {
            if (tempRoot->isLeftChildNode())
               nodeToDeleteParentPtr->setLeftNodePtr(
                   tempRoot->getLeftNodePtr());
            else
               nodeToDeleteParentPtr->setRightNodePtr(
                   tempRoot->getLeftNodePtr());

            delete tempRoot;
            return nodeToDeleteParentPtr->getLeftNodePtr();
         }
      }
   }
   // if should send left
   else if (data < tempRoot->getData() &&
            tempRoot->getLeftNodePtr() != nullptr) {
      return Delete(data, tempRoot->getLeftNodePtr());
   }
   // if should send right
   else if (data > tempRoot->getData() &&
            tempRoot->getRightNodePtr() != nullptr) {
      return Delete(data, tempRoot->getRightNodePtr());
   }
   // if on a leaf and no data was found break
   else {
      return nullptr;
   }
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
   if (root != nullptr) root->setParentNodePtr(nullptr);
}

template <typename T>
void BinarySearchTree<T>::Print(string prefix, Node<T>* node, bool isLeft) {
   if (node != nullptr) {
      cout << prefix;

      cout << (isLeft ? "├──" : "└──");  // └──

      // print the value of the node
      cout << node->getData() << std::endl;

      // enter the next tree level - left and right branch
      Print(prefix + (isLeft ? "│   " : "    "), node->getLeftNodePtr(), true);
      Print(prefix + (isLeft ? "│   " : "    "), node->getRightNodePtr(),
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