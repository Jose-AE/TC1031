#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"
using namespace std;

class LinkedList {
  private:
   Node* first;

  public:
   LinkedList();
   Node* getFirst();
   void setFirst(Node* first);
   void print();
   void addNode(Node* node);
   void addNodeFirst(Node* node);
   void addAtPos(Node* node, int pos);

   void mergeSort();
   Node* split(Node* head);
   Node* merge(Node* left, Node* right);
   void bubbleSort();
   void insertionSort();
   void insertSorted(Node* newNode);
   void selectionSort();
   Node* findMin(Node* start);
   void swapNodes(Node* node1, Node* node2);
};
#endif