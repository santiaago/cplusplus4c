// graph.cpp: Santiago Arias
// Description: Graph algo

#include <iostream>
#include <vector>

using namespace std;
//using std::vector;

class Edgenode{//node
public:
  Edgenode(): value(-1){ }
  Edgenode(int v):value(v){}
  int value;
};

class Graph{
public:
  Graph(): 
    nvertices(0), nedges(0), edges(0, vector<Edgenode*>(0)){}
  Graph(int number_nodes);
  int V(); // returns the number of vertices in the graph
  int E(); // returns the number of edges in the graph
  bool adjacent(int x, int y); // tests whether there is an edge from node x to node y.
  vector<Edgenode*> neighbors(int y); // lists all nodes y such that there is an edge from x to y.
  
  void add(int x, int y); // adds to G the edge from x to y, if it is not there.
  void remove(int x, int y); // removes the edge from x to y, if it is there.
  int get_node_value(Edgenode x); // returns the value associated with the node x.
  void set_node_value(Edgenode x, Edgenode a); // sets the value associated with the node x to a.
  int get_edge_value(int x, int y); // returns the value associated to the edge (x,y).
  void set_edge_value(int x, int y, Edgenode *v); // sets the value associated to the edge (x,y) to v.
  void print();
private:
  int nvertices; // number of vertices
  int nedges; // number of edges
  vector< vector<Edgenode*> > edges; // adjacency information

};

Graph::Graph(int nnodes):
  nedges(0), nvertices(0), edges(nnodes, vector<Edgenode*>(nnodes))
{
  for(int i = 0; i < nnodes; ++i){
    nvertices++;
    for(int j = i; j < nnodes; ++j){
      if(i == j){
	edges[i][j] = 0; // null pointer no loops
      } else {
	edges[i][j] = new Edgenode(1);
	edges[j][i] = edges[i][j];
	nedges++;
      }
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
vector<Edgenode*> Graph::neighbors(int y){
  if(y < edges.size()){
    return edges[y];
  }
  return vector<Edgenode*>();
}

// adds to G the edge from x to y, if it is not there.
void Graph::add(int x, int y){
  if(x < edges.size() && y < edges[x].size()){
    if(edges[x][y] == 0){
      edges[x][y] = new Edgenode(1);
      edges[y][x] = edges[x][y];
    }
  }
}

// removes the edge from x to y, if it is there.
void Graph::remove(int x, int y){
  if(x < edges.size() && y < edges[x].size()){
    edges[x][y] = 0;
    edges[y][x] = 0;
  }
}

// returns the value associated with the node x.
int Graph::get_node_value(Edgenode x){
  return x.value;
}

// sets the value associated with the node x to a.
void Graph::set_node_value(Edgenode x, Edgenode a){
  a.value = x.value;
}

// returns the value associated to the edge (x,y).
int Graph::get_edge_value(int x, int y){
  if(x < edges.size() && y < edges[x].size()){  
    if(edges[x][y])
    return edges[x][y]->value;
  }
  return 0;
}

// sets the value associated to the edge (x,y) 
void Graph::set_edge_value(int x, int y, Edgenode *e){
  if(x < edges.size() && y < edges[x].size()){  
    if(edges[x][y] && e){
      e->value = edges[x][y]->value;
    }
  }
}

void Graph::print(){
  for(int i = 0; i < edges.size(); ++i){
    for(int j = 0; j < edges.size(); ++j){
      if(edges[i][j])
	cout << edges[i][j]->value << " ";
      else
	cout << "x" << " ";
    }
    cout << endl;
  }
}

void test_graph(){
  cout << "test default constructor" << endl;
  Graph g1;
  g1.print();
  cout << endl;

  cout << "test size constructor" << endl;
  Graph g2(4);
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
  vector<Edgenode*> neighbors1 = g2.neighbors(0);
  for(int i = 0; i < neighbors1.size(); ++i){
    if(neighbors1[i])
      cout << "0 - " << i << endl;
  }
  cout << "test 2" << endl;
  vector<Edgenode*> neighbors2 = g2.neighbors(2);
  for(int i = 0; i < neighbors2.size(); ++i){
    if(neighbors2[i])
      cout << "2 - " << i << endl;
  }
  cout << endl;
  //   vector<Edgenode*> neighbors(int x, int y); // lists all nodes y such that there is an edge from x to y.
  
  //   void add(int x, int y); // adds to G the edge from x to y, if it is not there.
  //   void remove(int x, int y); // removes the edge from x to y, if it is there.
  //   int get_node_value(Edgenode x); // returns the value associated with the node x.
  //   void set_node_value(Edgenode x, Edgenode a); // sets the value associated with the node x to a.
  //   int get_edge_value(int x, int y); // returns the value associated to the edge (x,y).
  //   void set_edge_value(int x, int y, Edgenode *v); // sets the value associated to the edge (x,y) to v.
  //   void print();
  // private:
  //   int nvertices; // number of vertices
  //   int nedges; // number of edges
  //   vector< vector<Edgenode*> > edges; // adjacency information
  
}

int main(){
  test_graph();
  return 0;
}
