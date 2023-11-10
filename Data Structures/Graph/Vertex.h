#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Vertex {
  private:
   T data;
   vector<Vertex<T>> adj;

  public:
   Vertex(T data);
   void addAdj(Vertex<T> vertex);
   T getData();
   vector<Vertex<T>> getAdj();
   void print();
};
