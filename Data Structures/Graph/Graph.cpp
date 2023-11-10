
#include "Graph.h"

template <typename T>
Graph<T>::Graph() {}

template <typename T>
void Graph<T>::addVertex(T data, const initializer_list<T>& adj) {
   Vertex<T> v(data);

   for (const T& adjacentData : adj) {
      for (Vertex<T>& vertex : vertices) {
         if (vertex.getData() == adjacentData) {
            v.addAdj(vertex);
            vertex.addAdj(v);
         }
      }
   }

   vertices.push_back(v);
}

template <typename T>
void Graph<T>::print() {

   for (Vertex<T> vertex : vertices) {

      vector<Vertex<T>> vertexAdj = vertex.getAdj();

      cout << "[" << vertex.getData() << "]-";

      for (Vertex<T> vertex : vertexAdj) {
         cout << vertex.getData() << " ";
      }
      cout << "\n";
   }
}

// Templates
template class Graph<int>;