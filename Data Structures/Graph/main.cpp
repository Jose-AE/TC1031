#include "Graph.h"

int main(int argc, char const *argv[]) {

   Graph<int> graph;

   graph.addVertex(1);
   graph.addVertex(2, {1});
   graph.addVertex(3, {1, 2});

   graph.print();
   graph.bfs(5);
   graph.dfs();

   return 0;
}
