#pragma once
using namespace std;
template <typename T>
class Node_Queue {
  private:
   T data;
   Node_Queue* next;

  public:
   Node_Queue(T value);

   T getData();
   void setData(T value);
   Node_Queue* getNext();
   void setNext(Node_Queue* node);
};
