#include "Vertex.h"

template <typename T>
inline Vertex<T>::Vertex(T data) : data(data) {}

template <typename T>
inline void Vertex<T>::addAdjPtr(Vertex<T>* vertexPtr) {
   adjPtrs.push_back(vertexPtr);
}

template <typename T>
inline T& Vertex<T>::getData() {
   return data;
}

template <typename T>
inline vector<Vertex<T>*> Vertex<T>::getAdjPtrs() {
   return adjPtrs;
}

template <typename T>
inline void Vertex<T>::print() {}

template <typename T>
void Vertex<T>::setVisited(bool isVisited) {
   visited = isVisited;
}

template <typename T>
bool Vertex<T>::getVisited() {
   return visited;
}

// Templates
template class Vertex<int>;