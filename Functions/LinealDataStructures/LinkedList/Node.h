#pragma once

#include "Node.h"

class Node {
  private:
   int& data;
   Node* next;

  public:
   Node(int data);
   Node* getNext();
   int& getData();
   void setNext(Node* next);
   void setData(int data);
};

int main(int argc, char const* argv[]) {
   /* code */
   return 0;
}
