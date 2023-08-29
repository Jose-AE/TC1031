#pragma once

#include <cstdlib>
#include "Node.h"

using namespace std;

class LinkedList {
  private:
   Node* first;

  public:
   LinkedList();
   int& operator[](int index);

   void Append(int data);
};
