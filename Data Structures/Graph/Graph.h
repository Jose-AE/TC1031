#pragma once

#include <iostream>
#include <vector>
#include "Vertex.h"

using namespace std;

template <typename T>
class Graph {
  private:
   vector<Vertex<T>> vertices;

  public:
   Graph();
   void addVertex(T data, const initializer_list<T>& adj = {});
   void print();
};
