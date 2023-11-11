
#include "Graph.h"

template <typename T>
Graph<T>::Graph() {}

template <typename T>
void Graph<T>::addVertex(T data, const initializer_list<T>& adj) {
   Vertex<T>* newVertex = new Vertex<T>(data);

   for (const T& adjacentData : adj) {
      for (Vertex<T>* vertex : vertices) {
         if (vertex->getData() == adjacentData) {
            vertex->addAdjPtr(newVertex);
            newVertex->addAdjPtr(vertex);
         }
      }
   }

   vertices.push_back(newVertex);
}

template <typename T>
void Graph<T>::print() {

   for (Vertex<T>* vertex : vertices) {

      vector<Vertex<T>*> vertexAdjPtrs = vertex->getAdjPtrs();

      cout << "[" << vertex->getData() << "]-";

      for (Vertex<T>* adjVertex : vertexAdjPtrs) {
         cout << adjVertex->getData() << " ";
      }
      cout << "\n";
   }
}

template <typename T>
void Graph<T>::resetVisited() {
   for (Vertex<T>* vertex : vertices) {
      vertex->setVisited(false);
   }
}

template <typename T>
void Graph<T>::bfs() {
   queue<Vertex<T>*> vertexPtrQueue;

   vertexPtrQueue.push(vertices[0]);  // add first vertex to queue
   vertices[0]->setVisited(true);

   cout << "\n---[BFS]---\n";

   while (!vertexPtrQueue.empty()) {
      Vertex<T>* currentVertex = vertexPtrQueue.front();

      for (Vertex<T>* neighbor : currentVertex->getAdjPtrs()) {
         if (neighbor->getVisited() == false) {
            neighbor->setVisited(true);
            vertexPtrQueue.push(neighbor);
         }
      }

      cout << currentVertex->getData() << endl;

      vertexPtrQueue.pop();
   }

   resetVisited();
}

// Templates
template class Graph<int>;