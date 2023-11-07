#include "Vertex.h"

template <typename T>
inline Vertex<T>::Vertex(T data) : data(data) {}

template <typename T>
inline void Vertex<T>::addAdj(Vertex<T> data) {
   // search for a node with data and add it to list
}

template <typename T>
inline T Vertex<T>::getData() {
   return data;
}

template <typename T>
inline vector<Vertex<T>> Vertex<T>::getAdj() {
   return adj;
}

template <typename T>
inline void Vertex<T>::print() {}

// Templates
template class Vertex<int>;