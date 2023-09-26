#ifndef QUEUE_H
#define QUEUE_H
#include "../../../../../Functions/LinealDataStructures/LinkedList/Node.h"
template <typename T>
class Queue {
  private:
   Node<T> *first;

  public:
   Queue();
   void enque(Node<T> *node);
   void print();
   void deque();
   Node<T> *first();
};

#endif