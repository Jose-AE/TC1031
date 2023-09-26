#pragma once
using namespace std;
template <typename T>
class Node_Stack {
  private:
   T data;
   Node_Stack* next;

  public:
   Node_Stack(T value);

   T getData();
   void setData(T value);
   Node_Stack* getNext();
   void setNext(Node_Stack* node);
};
