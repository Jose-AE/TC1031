#include "Graph.h"
#include "User.h"

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
void Graph<T>::bfs(T target) {
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

      // if searching for target break on found
      if (target != T()) {
         if (currentVertex->getData() == target) break;
      }
   }

   resetVisited();
}

template <typename T>
void Graph<T>::dfs(T target) {

   stack<Vertex<T>*> vertexPtrStack;
   bool foundTarget = false;

   vertexPtrStack.push(vertices[0]);
   vertices[0]->setVisited(true);

   cout << "\n---[DFS]---\n";

   while (!vertexPtrStack.empty()) {
      Vertex<T>* currentVertex = vertexPtrStack.top();
      cout << currentVertex->getData() << endl;
      vertexPtrStack.pop();

      for (Vertex<T>* neighbor : currentVertex->getAdjPtrs()) {
         if (neighbor->getVisited() == false) {
            neighbor->setVisited(true);
            vertexPtrStack.push(neighbor);
         }
      }

      // if searching for target break on found
      if (target != T()) {
         if (currentVertex->getData() == target) break;
      }
   }

   resetVisited();
}

// Templates
template class Graph<User>;