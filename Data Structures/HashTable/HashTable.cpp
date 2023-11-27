#include "HashTable.h"

template <typename T>
int HashTable<T>::getHash(int key) {
   return key % 10;
}

template <typename T>
inline HashTable<T>::HashTable() {}

template <typename T>
void HashTable<T>::insert(int key, T value) {
   int index = getHash(key);

   BucketEntry<T> data;
   data.key = key;
   data.value = value;

   buckets[index].push_back(data);
}

template <typename T>
T HashTable<T>::find(int key) {

   int index = getHash(key);

   for (BucketEntry<T> entry : buckets[index]) {
      if (entry.key == key) return entry.value;
   }

   throw "Key not found";
}

// Templates
template class HashTable<std::string>;