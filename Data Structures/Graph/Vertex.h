#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Vertex {
  private:
   T data;
   vector<Vertex<T>*> adjPtrs;
   bool visited = false;

  public:
   Vertex(T data);
   void addAdjPtr(Vertex<T>* vertexPtr);
   T& getData();
   vector<Vertex<T>*> getAdjPtrs();
   void print();
   void setVisited(bool isVisited);
   bool getVisited();
};
