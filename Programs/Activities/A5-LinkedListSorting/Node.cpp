#include "Node.h"

Node::Node(int data) {
   this->data = data;
   next = nullptr;
}
int Node::getData() { return data; }
void Node::setData(int data) { this->data = data; }
Node* Node::getNext() { return next; }
void Node::setNext(Node* next) { this->next = next; }
