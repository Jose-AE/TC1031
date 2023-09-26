#ifndef STACK_H
#define STACK_H
#include "../../../../../Functions/LinealDataStructures/LinkedList/Node.h"

template <typename T>
class Stack {
  private:
   Node<T> *first;

  public:
   Stack();
   void push(Node<T> *node);
   void print();
   void pop();
   Node<T> *top();
};

#endif