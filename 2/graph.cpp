// graph.cpp: Santiago Arias
// Description: Graph ATD

#include "graph.h"

// Graph constructor:
// This is the main constructor, pass a density parameter to create a random graph.
Graph::Graph(const int number_vertices, const double dense_edge, const int range_dist):
  nedges(0), nvertices(number_vertices), edges(number_vertices, vector<Edge*>(number_vertices)), node_values(number_vertices, 0), density_edge(dense_edge), range_distance(range_dist){

  // Initialize random seed
  srand(time(NULL));

  // Initialize graph with random density and distance
  double random_distance;
  for(int i = 0; i < edges.size(); ++i){
    nvertices++;
    for(int j = i; j < edges.size(); ++j){
      if(i == j){
  	edges[i][j] = NULL; // null pointer:  no loops in Graph
      } else {
	// manage density in graph
	if( ((double) rand() / (RAND_MAX)) < density_edge){
	  // generate random number between 1 and range_distance
	  random_distance = rand() %range_distance + 1;
	  edges[i][j] = new Edge(random_distance);
	  edges[j][i] = edges[i][j]; // undirected graph, connect both vertex
	  nedges++;
	}
      }
    }
  }
}

// Graph constructor:
// This constructor an empty graph that you can then create by hand.
Graph::Graph(const int number_vertices):
  nedges(0), nvertices(number_vertices), edges(number_vertices, vector<Edge*>(number_vertices)), node_values(number_vertices, 0), density_edge(0), range_distance(0){}


// initialize sample graph (with distances of edges at 1 and fully connected)
void Graph::initialize(){
  for(int i = 0; i < edges.size(); ++i){
    node_values[i] = 1;
    nvertices++;
    for(int j = i; j < edges.size(); ++j){
      if(i == j){
	edges[i][j] = NULL; // null pointer no loops
      } else {
	edges[i][j] = new Edge(1);
	edges[j][i] = edges[i][j]; // undirected graph.
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
bool Graph::adjacent(const int x, const int y){
  if(x < edges.size() && y < edges[x].size()){
    if(edges[x][y] != NULL)
      return true;
  }
  return false;
}

// lists all nodes y such that there is an edge from x to y.
vector<Edge*> Graph::neighbors(const int x){
  if(x < edges.size()){
    return edges[x];
  }
  return vector<Edge*>();
}

// adds to G the edge from x to y, if it is not there.
void Graph::add(const int x, const int y){
  if(x < edges.size() && y < edges[x].size()){
    if(edges[x][y] == NULL){
      edges[x][y] = new Edge(1);
      edges[y][x] = edges[x][y]; // undirected graph
      nedges++;
    }
  }
}

// removes the edge from x to y, if it is there.
void Graph::remove(const int x, const int y){
  if(x < edges.size() && y < edges[x].size()){
    if(edges[x][y]){
      edges[x][y] = NULL;
      edges[y][x] = NULL; // undirected graph
      nedges--;
    }
  }
}

// returns the value associated with the node x.
int Graph::get_node_value(const int x){
  if(0 <= x < node_values.size())
    return node_values[x];
  return 0;
}

// sets the value associated with the node x to a.
void Graph::set_node_value(const int x, const int a){
  if(0 <= x <= node_values.size() &&
     0 <= a <= node_values.size())
    node_values[a]= node_values[x];
}

// returns the value associated to the edge (x,y).
double Graph::get_edge_value(const int x, const int y){
  if(x < edges.size() && y < edges[x].size()){  
    if(edges[x][y])
      return edges[x][y]->cost;
  }
  return 0;
}

// sets the value associated to the edge (x,y) to v.
void Graph::set_edge_value(const int x, const int y, Edge *v){
  if(x < edges.size() && y < edges[x].size()){  
    if(edges[x][y] && v){
      v->cost = edges[x][y]->cost;
    }
  }
}

// gets a pointer to the edge associated to (x,y)
Edge* Graph::get_edge(const int x, const int y){
  if(x < edges.size() && y < edges[x].size()){  
    return edges[x][y];
  }
  return NULL;
}

// print adjacency matrix
void Graph::print(){
  for(int i = 0; i < edges.size(); ++i){
    for(int j = 0; j < edges.size(); ++j){
      if(edges[i][j])
	cout << edges[i][j]->cost << "\t";
      else
	cout << "x" << "\t";
    }
    cout << endl;
  }
}
