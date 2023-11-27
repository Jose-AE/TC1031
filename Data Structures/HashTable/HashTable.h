#pragma once

#include <string>
#include <vector>

using namespace std;

template <typename T>
struct BucketEntry {
   int key;
   T value;
};

template <typename T>
class HashTable {
  private:
   vector<BucketEntry<T>> buckets[10];

   int getHash(int key);

  public:
   HashTable();
   void insert(int key, T value);
   T find(int key);
};
