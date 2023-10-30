#pragma once

template <typename T>
class Node {
  private:
   T data;
   Node<T>* leftNodePtr = nullptr;
   Node<T>* rightNodePtr = nullptr;
   Node<T>* parentNodePtr = nullptr;

  public:
   Node();
   Node(T data, Node<T>* leftNodePtr = nullptr,
        Node<T>* rightNodePtr = nullptr);

   T getData();
   void setData(T data);
   Node<T>* getRightNodePtr();
   Node<T>* getLeftNodePtr();
   Node<T>* getParentNodePtr();

   void setLeftNodePtr(Node<T>* node);
   void setRightNodePtr(Node<T>* node);
   void setParentNodePtr(Node<T>* node);
   void Print();

   int getBalanceFactor();
   int getHeight();

   bool isLeftChildNode();
};
