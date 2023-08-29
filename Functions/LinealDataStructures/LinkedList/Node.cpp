#include "Node.h"

Node::Node(int data) : data(data), next(nullptr) {}

Node* Node::getNext() { return next; }

int& Node::getData() { return data; }

void Node::setData(int data) { this->data = data; }

void Node::setNext(Node* node) { this->next = next; }
