#pragma once

template <typename T>
class Node {
  private:
   T data;
   Node<T>* leftNodePtr;
   Node<T>* rightNodePtr;

  public:
   Node();
   Node(T data, Node<T>* leftNodePtr = nullptr,
        Node<T>* rightNodePtr = nullptr);

   T getData();
   void setData(T data);
   Node<T>* getRightNodePtr();
   Node<T>* getLeftNodePtr();
   void setLeftNodePtr(Node<T>* node);
   void setRightNodePtr(Node<T>* node);
   void Print();
};
