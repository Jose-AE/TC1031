// #include "LinkedList.h"
// #include <stdexcept>

// template <typename T>
// LinkedList<T>::LinkedList(T firstVal) : first(new Node<T>(firstVal)) {}

// template <typename T>
// void LinkedList<T>::Append(T&& data) {
//    length++;
//    Node<T>& nextNode = first;
//    while (nextNode.getNext() != nullptr) {
//       nextNode = nextNode.getNext();
//    }
//    nextNode.setData(data);
// }

// template <typename T>
// T& LinkedList<T>::operator[](int index) {
//    if (index > length) throw runtime_error("Index is out of range");

//    int counter = 0;
//    Node<T>& nextNode = first;
//    for (int i = 0; i < index; i++) {
//       nextNode = nextNode.getNext();
//    }

//    delete counter;

//    return nextNode.getData();
// }
