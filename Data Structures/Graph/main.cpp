#include "Graph.h"

int main(int argc, char const *argv[]) {

   Graph<int> graph;

   // graph.addVertex(7);
   // graph.addVertex(6, {7});
   // graph.addVertex(2, {6});
   // graph.addVertex(5, {6});
   // graph.addVertex(3, {5, 6});
   // graph.addVertex(1, {2, 3});
   // graph.addVertex(50, {2});

   graph.addVertex(1);
   graph.addVertex(2, {1});
   graph.addVertex(3, {1});
   graph.addVertex(50, {2});
   graph.addVertex(6, {2});
   graph.addVertex(5, {3});
   graph.addVertex(7, {6});

   graph.print();
   graph.bfs();
   graph.dfs();

   return 0;
}
