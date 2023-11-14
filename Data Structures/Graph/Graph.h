#pragma once

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "Vertex.h"

using namespace std;

template <typename T>
class Graph {
  private:
   vector<Vertex<T>*> vertices;

  public:
   Graph();
   void addVertex(T data, const initializer_list<T>& adj = {});
   void print();
   void resetVisited();
   void bfs(T target = T());
   void dfs(T target = T());
};
