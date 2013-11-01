// graph.cpp: Santiago Arias
// Description: Graph algo

#include <iostream>

using namespace std;

class Edgenode{//node
public:
  Edgenode(): value(-1){ }
  int value;
};

class Graph{
public:
  Graph(): nvertices(0), nedges(0){}
  Graph(int number_nodes);
  int V(); // returns the number of vertices in the graph
  int E(); // returns the number of edges in the graph
  bool adjacent(int x, int y); // tests whether there is an edge from node x to node y.
  bool neighbors(int x, int y); // lists all nodes y such that there is an edge from x to y.
  void add(int x, int y); // adds to G the edge from x to y, if it is not there.
  void remove(int x, int y); // removes the edge from x to y, if it is there.
  int get_node_value(Edgenode x); // returns the value associated with the node x.
  void set_node_value(Edgenode x, Edgenode a); // sets the value associated with the node x to a.
  int get_edge_value(int x, int y); // returns the value associated to the edge (x,y).
  void set_edge_value(int x, int y, Edgenode v); // sets the value associated to the edge (x,y) to v.
private:
  vector<vector<*Edgenode>> edges; // adjacency information
  int nvertices; // number of vertices
  int nedges; // number of edges
};

Graph::Graph(int nnodes){
  for(int i = 0; i < nnodes; ++i)
    for(int j = i; j < nnodes; ++j){
      if(i == j)
	edges[i][j] = 0; // null pointer no loops
      else{
	edges[i][j] = new Edgenode(1);
	edges[i][j] = edges[i][j];
	nedges++;
	nvertices += 2;
      }
    }
}

// returns the number of vertices in the graph
int Graph::V(){
  return nvertices;
}

// returns the number of edges in the graph
int Graph::E(){
  return nedges;
}

// tests whether there is an edge from node x to node y.
bool Graph::adjacent(int x, int y){
  if(x < edges.size() && y < edges[x].size()){
    if(edges[x][y] != 0)
      return true;
  }
  return false;
}

// lists all nodes y such that there is an edge from x to y.
Vector<Edgenode> Graph::neighbors(int x, int y){
  if(y < edges.size()){
    return edges[y];
  }
  return vector<Edgenode>();
}

// adds to G the edge from x to y, if it is not there.
void Graph::add(int x, int y){
  if(x < edges.size() && y < edges[x].size()){
    edges[x][y] = 0;
    edges[x][y] = 1;
  }
}

// removes the edge from x to y, if it is there.
void Graph::delete(int x, int y){
  if(x < edges.size() && y < edges[x].size()){
    edges[x][y] = -1;
    edges[y][x] = -1;
  }
}

// returns the value associated with the node x.
int Graph::get_node_value(Node x){
  return x.value;
}

// sets the value associated with the node x to a.
void Graph::set_node_value(Node x, Node a){
  a.value = x.value;
}

// returns the value associated to the edge (x,y).
int get_edge_value(int x, int y){
  if(x < edges.size() && y < edges[x].size()){  
    return edges[x][y];
  }
  return 0;
}

// sets the value associated to the edge (x,y) 
void set_edge_value(int x, int y, int v){
  if(x < edges.size() && y < edges[x].size()){  
    edges[x][y] = v;
  }
}

int main(){

  return 0;
}
