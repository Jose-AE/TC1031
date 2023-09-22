#include <iostream>
#include "LinkedList.h"
#include "Node.h"

using namespace std;

int main() {

   cout << "----------Bubble sort:------------" << endl;

   LinkedList list1;
   list1.addNode(new Node(34));
   list1.addNode(new Node(6));
   list1.addNode(new Node(90));
   list1.addNode(new Node(53));
   list1.addNode(new Node(21));
   list1.bubbleSort();

   list1.print();

   cout << "----------Merge sort:------------" << endl;

   LinkedList list2;
   list2.addNode(new Node(34));
   list2.addNode(new Node(6));
   list2.addNode(new Node(90));
   list2.addNode(new Node(53));
   list2.addNode(new Node(21));
   list2.mergeSort();

   list2.print();

   cout << "----------insertion sort:------------" << endl;

   LinkedList list3;
   list3.addNode(new Node(34));
   list3.addNode(new Node(6));
   list3.addNode(new Node(90));
   list3.addNode(new Node(53));
   list3.addNode(new Node(21));
   list3.insertionSort();

   list3.print();

   cout << "----------selection sort:------------" << endl;

   LinkedList list;
   list.addNode(new Node(34));
   list.addNode(new Node(6));
   list.addNode(new Node(90));
   list.addNode(new Node(53));
   list.addNode(new Node(21));
   list.selectionSort();

   list.print();
}