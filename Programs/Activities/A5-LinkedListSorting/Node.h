#ifndef NODE_H
#define NODE_H
class Node {
  private:
   int data;
   Node *next;

  public:
   Node(int data);
   int getData();
   void setData(int data);
   Node *getNext();
   void setNext(Node *next);
};

#endif