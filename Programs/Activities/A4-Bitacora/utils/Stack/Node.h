#pragma once

using namespace std;
template <typename T>
class Node {
  private:
   T data;
   Node* next;

  public:
   Node(T value);

   T getData();
   void setData(T value);
   Node* getNext();
   void setNext(Node* node);
};
