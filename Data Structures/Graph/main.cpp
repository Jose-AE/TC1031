#include "Graph.h"

int main(int argc, char const *argv[]) {

   Graph<int> graph;

   graph.addVertex(0);
   graph.addVertex(1, {0});
   graph.addVertex(2, {0, 1});

   graph.print();
   graph.bfs();
   graph.dfs();

   return 0;
}
