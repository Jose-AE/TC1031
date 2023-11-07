
#include "Graph.h"

template <typename T>
Graph<T>::Graph() {}

template <typename T>
void Graph<T>::addVertex(T data, const initializer_list<T>& adj) {
   Vertex<T> v(data);

   for (T vertex : adj) {
      cout << "d";
   }

   // adj.push_back(v);
}

// Templates
template class Graph<int>;