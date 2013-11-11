// graph.cpp: Santiago Arias
// Description: Graph ATD and Dijkstra’s algorithm

#include <iostream>
#include <vector>
#include <limits> // std::numeric_limits
#include <queue>
#include <stack>

#include "graph.h"
#include "shortest_path.h"

const int kSampleSize = 10000; // sample size to compute average of cost path

using namespace std;

void test_graph_class(){
  cout << "test default constructor" << endl;
  Graph g1;
  g1.print();
  cout << endl;

  cout << "test size constructor" << endl;
  Graph g2(4);
  g2.initialize();
  g2.print();
  cout << endl;

  cout << "test number of vertices in graph" << endl;
  cout << boolalpha << (g1.V() == 0) << " " << (g2.V() == 4) << endl;
  cout << endl;

  cout << "test number of edges in graph" << endl;
  cout << boolalpha << (g1.E() == 0) << " " << (g2.E() == 6) << endl;
  cout << endl;

  cout << "test adjacent method" << endl;
  bool result;
  bool expected;
  for(int i = 0; i < g2.V(); ++i){
    for(int j = i; j < g2.V(); ++j){
      result = g2.adjacent(i,j);
      expected = (i == j)? false:true;
      cout << boolalpha << (result == expected) << " ";
    }
    cout << endl;
  }
  cout << endl;

  cout << "test neighbors method" << endl;
  cout << "neighbors of node 0" << endl;
  vector<Edge*> neighbors1 = g2.neighbors(0);
  for(int i = 0; i < neighbors1.size(); ++i){
    if(neighbors1[i])
      cout << "0 - " << i << endl;
  }

  cout << "neighbors of node 2" << endl;
  vector<Edge*> neighbors2 = g2.neighbors(2);
  for(int i = 0; i < neighbors2.size(); ++i){
    if(neighbors2[i])
      cout << "2 - " << i << endl;
  }
  cout << endl;

  cout << "testing add method" << endl;
  Graph g3(4);
  g3.add(0,1);
  g3.add(0,2);
  g3.add(1,3);
  g3.add(2,3);
  g3.print();
  cout << endl;

  cout << "testing remove method" << endl;
  cout << boolalpha << (g3.E() == 4) << endl;
  cout << "neigbors of 0" << endl;
  vector<Edge*> neighbors3 = g3.neighbors(0);
  for(int i = 0; i < neighbors3.size(); ++i){
    if(neighbors3[i])
      cout << "0 - " << i << endl;
  }
  g3.remove(0,1);
  g3.remove(0,0); // should do nothing
  g3.remove(1,1); // should do nothing
  cout << boolalpha << (g3.E() == 3) << endl;
  cout << "neigbors of 0" << endl;
  neighbors3 = g3.neighbors(0);
  for(int i = 0; i < neighbors3.size(); ++i){
    if(neighbors3[i])
      cout << "0 - " << i << endl;
  }
  g3.print();
  cout << endl;

  cout << "test the get_node_value method" << endl;
  for(int i = 0; i < g3.V(); ++i){
    cout << "node value of " << i << " is " << g3.get_node_value(i) << endl;
  }
  cout << endl;

  cout << "test the set_node_value method" << endl;
  cout << g3.get_node_value(0) << " " << g3.get_node_value(1) << endl;
  g3.set_node_value(0,1);
  cout << g3.get_node_value(0) << " " << g3.get_node_value(1) << endl;  
  cout << endl;

  cout << "test get_edge_value method" << endl;
  for(int i = 0; i < g3.V(); ++i){
    for(int j = i; j < g3.V(); ++j)
      if(i != j)
	cout << "edge value of (" << i << " , " << j << ") is: " << g3.get_edge_value(i,j) << endl;
  }
  cout << endl;

  cout << "test set_edge_value method" << endl;
  Edge *edgeptr = g3.get_edge(0,2);
  cout << "(0,1) : "<< g3.get_edge_value(0,2) << endl;
  cout << "(0,2) : "<< g3.get_edge_value(1,3) << endl;
  g3.set_edge_value(1,3,edgeptr);
  cout << "(0,1) : "<< g3.get_edge_value(0,2) << endl;
  cout << "(0,2) : "<< g3.get_edge_value(1,3) << endl;

  cout << endl;

  cout << "test Graph with density" << endl;
  cout << endl << "density of 10%" <<endl;
  Graph g4(10,0.1, 10);
  g4.print();
  cout << endl << "density of 20%" <<endl;
  Graph g5(10,0.2, 10);
  g5.print();
  cout << endl << "density of 40%" <<endl;
  Graph g6(10,0.4, 10);
  g5.print();
}

Graph* test_init_graph(){
  Graph *g = new Graph(4);
  g->add(0,1);
  g->add(0,2);
  g->add(1,3);
  g->add(2,3);
  return g;
}


void test_shortest_path_class(){
  cout << "test_shortest_path_class" << endl;

  cout << "initialize graph" << endl;
  ShortestPath sp;
  Graph *g = test_init_graph();
  g->print();
  cout << endl;

  cout << "testing vertices" << endl;
  vector<int> graph_vertices = sp.vertices(g);
  for(int i = 0; i < graph_vertices.size(); ++i){
    cout << i << " ";
  }
  cout << endl;

  cout << "test shortest path" << endl;
  stack<int> path = sp.path(g, 0, 3);
  while (!path.empty())
  {
    cout << path.top() << " ";
    path.pop();
  }
  cout << "cost: " << sp.path_size(g,0,3);
  cout << endl;

  cout << "test shortest path #2" << endl;
  Graph *g2 = new Graph(10,0.4, 10);
  g2->print();
  stack<int> path2 = sp.path(g2, 0, 9);
  while (!path2.empty())
  {
    cout << path2.top() << " ";
    path2.pop();
  }
  cout << "cost: " << sp.path_size(g2,0,9);
  cout << endl;

  cout << "test shortest path #3" << endl;
  Graph *g3 = new Graph(kNumber_nodes,0.2, 10);
  
  stack<int> path3 = sp.path(g3, 0, 9);
  while (!path3.empty())
  {
    cout << path3.top() << " ";
    path3.pop();
  }

  cout << "cost: " << sp.path_size(g3,0,9);
  cout << endl;

  cout << "test shortest path #4" << endl;
  Graph *g4 = new Graph(kNumber_nodes,0.4, 10);
  stack<int> path4 = sp.path(g4, 0, 9);
  while (!path4.empty())
  {
    cout << path4.top() << " ";
    path4.pop();
  }
  cout << "cost: " << sp.path_size(g4,0,9);
  cout << endl;

  cout << "test shortest path #5" << endl;
  Graph *g5 = new Graph(kNumber_nodes,0.2, 10);
  stack<int> path5 = sp.path(g5, 0, 49);
  while (!path5.empty())
  {
    cout << path5.top() << " ";
    path5.pop();
  }
  cout << "cost: " << sp.path_size(g5,0,49); 
  cout << endl;
        
}

void tests(){
  cout << "----------" << endl;
  test_graph_class();
  cout << "----------" << endl;
  test_shortest_path_class();
  cout << "----------" << endl;
}

int main(){
  tests();
  cout << "200 words of c++" << endl;

  cout << "Average path of Graph with density 20%: ";
  double avg_20_precent(0);
  double avg_40_precent(0);

  double test_population(0);
  double current_cost(0);
  ShortestPath sp;
  stack<int> path;
  
  for(int i = 0; i < kSampleSize; ++i){
    Graph *g = new Graph(kNumber_nodes, kDensity_20_percent, 10);
    current_cost = sp.path_size(g, 0, 49);
    if(current_cost != 0){
      avg_20_precent += current_cost;
      test_population++;
    }
  }
  avg_20_precent = double(avg_20_precent)/test_population;
  cout << avg_20_precent << endl;
    
  cout << "Average path of Graph with density 40%: ";
  current_cost = 0;
  test_population = 0;
  for(int i = 0; i < kSampleSize; ++i){
    Graph *g = new Graph(kNumber_nodes, kDensity_40_percent, 10);
    current_cost = sp.path_size(g, 0, 49);
    if(current_cost != 0){
      avg_40_precent += current_cost;
      test_population++;
    }
  }
  avg_40_precent = double(avg_40_precent)/test_population;
  cout << avg_40_precent << endl;;

  return 0;
}
