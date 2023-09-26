#pragma once
#include "Node_Stack.h"
template <typename T>
class Stack {
  private:
   Node_Stack<T> *first;

  public:
   Stack();
   void push(Node_Stack<T> *node);
   void print();
   void pop();
   Node_Stack<T> *top();
};
