#include <iostream>
#include "Graph.h"
#include "User.h"

using namespace std;

int main() {

   User user1("Jose");
   User user2("Mark");
   User user3("Alice");
   User user4("Bob");
   User user5("Emily");
   User user6("Chris");
   User user7("Sara");
   User user8("David");
   User user9("Lily");
   User user10("Tom");
   User user11("Jessica");
   User user12("Alex");
   User user13("Olivia");
   User user14("Michael");
   User user15("Sophie");
   User user16("Daniel");
   User user17("Mia");
   User user18("Kevin");
   User user19("Emma");
   User user20("Ryan");

   Graph<User> graph;

   graph.addVertex(user1);
   graph.addVertex(user2, {user1});
   graph.addVertex(user3, {user1, user2});
   graph.addVertex(user4, {user2, user3});
   graph.addVertex(user5, {user3, user4});
   graph.addVertex(user6, {user4, user5});
   graph.addVertex(user7, {user5, user6});
   graph.addVertex(user8, {user6, user7});
   graph.addVertex(user9, {user7, user8});
   graph.addVertex(user10, {user8, user9});
   graph.addVertex(user11, {user9, user10});
   graph.addVertex(user12, {user10, user11});
   graph.addVertex(user13, {user11, user12});
   graph.addVertex(user14, {user12, user13});
   graph.addVertex(user15, {user13, user14});
   graph.addVertex(user16, {user14, user15});
   graph.addVertex(user17, {user15, user16});
   graph.addVertex(user18, {user16, user17});
   graph.addVertex(user19, {user17, user18});
   graph.addVertex(user20, {user18, user19});

   graph.print();
   graph.bfs(user18);
   graph.dfs(user18);

   return 0;
}
