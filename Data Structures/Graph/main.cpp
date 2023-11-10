#include "Graph.h"

int main(int argc, char const *argv[]) {

   Graph<int> graph;

   graph.addVertex(15);
   graph.addVertex(6, {15});
   graph.addVertex(8, {15, 6});

   graph.print();

   return 0;
}
