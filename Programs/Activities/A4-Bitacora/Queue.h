#pragma once
#include "Node_Queue.h"
template <typename T>
class Queue {
  private:
   Node_Queue<T>* first;

  public:
   Queue();
   void enque(Node_Queue<T>* node);
   void print();
   void deque();
   Node_Queue<T>* getFirst();
};
