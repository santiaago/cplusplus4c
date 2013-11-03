// graph.cpp: Santiago Arias
// Description: Graph algo

#include <iostream>
#include <vector>
#include <limits> // std::numeric_limits
#include <queue>
using namespace std;


class Edgenode{//node
public:
  Edgenode(): value(-1){ }
  Edgenode(int v):value(v){}
  double value; // distance
};

class Graph{
public:
  Graph(): 
    nvertices(0), nedges(0), edges(0, vector<Edgenode*>(0)), node_values(0,0){}
  Graph(int number_nodes);
  Graph(int nnodes, double density);

  void initialize();
  int V(); // returns the number of vertices in the graph
  int E(); // returns the number of edges in the graph
  bool adjacent(int x, int y); // tests whether there is an edge from node x to node y.
  vector<Edgenode*> neighbors(int y); // lists all nodes y such that there is an edge from x to y.
  
  void add(int x, int y); // adds to G the edge from x to y, if it is not there.
  void remove(int x, int y); // removes the edge from x to y, if it is there.
  int get_node_value(int x); // returns the value associated with the node x.
  void set_node_value(int x, int a); // sets the value associated with the node x to a.
  double get_edge_value(int x, int y); // returns the value associated to the edge (x,y).
  void set_edge_value(int x, int y, Edgenode *v); // sets the value associated to the edge (x,y) to v.
  Edgenode* get_edge_node(int x, int y);
  void print();
private:
  int nvertices; // number of vertices
  int nedges; // number of edges
  vector< vector<Edgenode*> > edges; // adjacency information
  vector< int> node_values;
  double density;
};

Graph::Graph(int nnodes):
  nedges(0), nvertices(nnodes), edges(nnodes, vector<Edgenode*>(nnodes)), node_values(nnodes, 0){}

Graph::Graph(int nnodes, double dense):
  nedges(0), nvertices(nnodes), edges(nnodes, vector<Edgenode*>(nnodes)), node_values(nnodes, 0), density(dense){

  // Initialize random seed
  srand(time(NULL));
  double random_distance;
  for(int i = 0; i < edges.size(); ++i){
    // might not need this : node_values[i] = 1;
    nvertices++;
    for(int j = i; j < edges.size(); ++j){
      if(i == j){
  	edges[i][j] = NULL; // null pointer no loops
      } else {
	if( ((double) rand() / (RAND_MAX)) < density){
	  // generate random number between 1 and 10
	  random_distance = rand() %10 + 1;
	  edges[i][j] = new Edgenode(random_distance);
	  edges[j][i] = edges[i][j]; // undirected graph.
	  nedges++;
	}
      }
    }
  }
}

void Graph::initialize(){
  for(int i = 0; i < edges.size(); ++i){
    node_values[i] = 1;
    nvertices++;
    for(int j = i; j < edges.size(); ++j){
      if(i == j){
	edges[i][j] = NULL; // null pointer no loops
      } else {
	edges[i][j] = new Edgenode(1);
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
      nedges++;
    }
  }
}

// removes the edge from x to y, if it is there.
void Graph::remove(int x, int y){
  if(x < edges.size() && y < edges[x].size()){
    if(edges[x][y]){
      edges[x][y] = 0;
      edges[y][x] = 0;
      nedges--;
    }
  }
}

// returns the value associated with the node x.
int Graph::get_node_value(int x){
  if(0 <= x < node_values.size())
    return node_values[x];
  return 0;
}

// sets the value associated with the node x to a.
void Graph::set_node_value(int x, int a){
  if(0 <= x <= node_values.size() &&
     0 <= a <= node_values.size())
    node_values[a]= node_values[x];
}

// returns the value associated to the edge (x,y).
double Graph::get_edge_value(int x, int y){
  if(x < edges.size() && y < edges[x].size()){  
    if(edges[x][y])
      return edges[x][y]->value;
  }
  return 0;
}

// sets the value associated to the edge (x,y) to v.
void Graph::set_edge_value(int x, int y, Edgenode *v){
  if(x < edges.size() && y < edges[x].size()){  
    if(edges[x][y] && v){
      v->value = edges[x][y]->value;
    }
  }
}

// gets a pointer to the edge associated to (x,y)
Edgenode* Graph::get_edge_node(int x, int y){
  if(x < edges.size() && y < edges[x].size()){  
    return edges[x][y];
  }
  return NULL;
}

void Graph::print(){
  for(int i = 0; i < edges.size(); ++i){
    for(int j = 0; j < edges.size(); ++j){
      if(edges[i][j])
	cout << edges[i][j]->value << "\t";
      else
	cout << "x" << "\t";
    }
    cout << endl;
  }
}

class DistanceComparer{
public:
  DistanceComparer(const bool & reverse_param = true): reverse(reverse_param){}
  bool operator() (const pair<int,double> left_hand_side, const pair<int,double> right_hand_side){
    if(reverse)
      return (left_hand_side.second > right_hand_side.second);
    return (left_hand_side.second < right_hand_side.second);
  }
private:
  bool reverse;
  
};

class ShortestPath{
public:
  vector<int> vertices(Graph* g); // list of vertices in Graph G(V,E).  
  vector<int>/*queue<int>*/ path(Graph* g, int u, int w); //path(G, u, w): find shortest path in graph g between u-w and returns the sequence of vertices representing shorest path u-v1-v2-…-vn-w.
  double path_size(int u, int w); // path_size(u, w): return the path cost associated with the shortest path.

};

// list of vertices in Graph G(V,E).
vector<int> ShortestPath::vertices(Graph* g){
  vector<int> vertices;
  for(int i = 0; i < g->V(); ++i)
    vertices.push_back(i);
  return vertices;
}

// path(u, w): find shortest path between u-w 
// and returns the sequence of vertices representing shorest path
//  u-v1-v2-…-vn-w.
//queue<int> ShortestPath::path(Graph* g, int source, int target){
vector<int> ShortestPath::path(Graph* g, int source, int target){
  // sortest path algorithm here
  
  // initialization
  typedef priority_queue< pair<int,double>, vector< pair<int,double> >, DistanceComparer> PriorityQueue;

  PriorityQueue q(true); // reverse (faster first)

  vector<double> distances;
  vector<bool> visited;
  vector<int> previous;

  vector<int> graph_vertices = vertices(g);
  for(int i = 0; i < graph_vertices.size(); ++i){
    distances.push_back(numeric_limits<double>::max()); // unknown distance from u to w
    visited.push_back(false); // nodes have not been visited
    previous.push_back(-1); // previous node in optimal path "-1" <=> undifined
  }

  distances[source] = 0; // distance from source to source
  q.push(make_pair(source, distances[source])); // start with the source node

  int current_vertex;
  while( !q.empty()){
    // vertex in Q with smallest distance and that has not yet neen visited
    current_vertex = q.top().first;
    q.pop();
    if(visited[current_vertex]){
      continue;
    }
    if(current_vertex == target){
      // shortes path found!
      break;
    }
    visited[current_vertex] = true; // mark node as visited
    
    // for each neighbor v of current_vertex
    double accumulate_distance = 0;
    vector<Edgenode*> neighbor = g->neighbors(current_vertex);
    for(int i = 0; i < neighbor.size(); ++i){
      if(neighbor[i]){
	accumulate_distance = distances[current_vertex] + neighbor[i]->value;
	if(accumulate_distance < distances[i] && !visited[i]){
	  distances[i] = accumulate_distance;
	  previous[i] = current_vertex;
	  q.push(make_pair(i, distances[i]));
	}
      }
    }
  }
  // build path sequence
  vector<int> sequence;
  current_vertex = target;
  while(previous[current_vertex] != -1){
    sequence.push_back(current_vertex);
    current_vertex = previous[current_vertex];
  }
  sequence.push_back(current_vertex); // push that last element

  return sequence;
}

 // path_size(u, w): return the path cost associated with the shortest path.
double ShortestPath::path_size(int u, int w){
  return 0;
}

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
  vector<Edgenode*> neighbors1 = g2.neighbors(0);
  for(int i = 0; i < neighbors1.size(); ++i){
    if(neighbors1[i])
      cout << "0 - " << i << endl;
  }

  cout << "neighbors of node 2" << endl;
  vector<Edgenode*> neighbors2 = g2.neighbors(2);
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
  vector<Edgenode*> neighbors3 = g3.neighbors(0);
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
  Edgenode *edgenodeptr = g3.get_edge_node(0,2);
  cout << "(0,1) : "<< g3.get_edge_value(0,2) << endl;
  cout << "(0,2) : "<< g3.get_edge_value(1,3) << endl;
  g3.set_edge_value(1,3,edgenodeptr);
  cout << "(0,1) : "<< g3.get_edge_value(0,2) << endl;
  cout << "(0,2) : "<< g3.get_edge_value(1,3) << endl;

  cout << endl;

  cout << "test Graph with density" << endl;
  cout << endl << "density of 10%" <<endl;
  Graph g4(10,0.1);
  g4.print();
  cout << endl << "density of 20%" <<endl;
  Graph g5(10,0.2);
  g5.print();
  cout << endl << "density of 40%" <<endl;
  Graph g6(10,0.4);
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
  vector<int> path = sp.path(g, 0, 3);
  for(int i = path.size()-1; i >= 0; --i){
    cout << path[i] << " ";
  }
  cout << endl;

  cout << "test shortest path #2" << endl;
  Graph *g2 = new Graph(10,0.4);
  g2->print();
  vector<int> path2 = sp.path(g2, 0, 9);
  for(int i = path2.size()-1; i >= 0; --i){
    cout << path2[i] << " ";
  }
  cout << endl;

  cout << "test shortest path #3" << endl;
  Graph *g3 = new Graph(50,0.2);
  
  vector<int> path3 = sp.path(g3, 0, 9);
  for(int i = path3.size()-1; i >= 0; --i){
    cout << path3[i] << " ";
  }
  cout << endl;


  cout << "test shortest path #4" << endl;
  Graph *g4 = new Graph(50,0.4);
  vector<int> path4 = sp.path(g4, 0, 9);
  for(int i = path4.size()-1; i >= 0; --i){
    cout << path4[i] << " ";
  }
  cout << endl;

  cout << "test shortest path #5" << endl;
  Graph *g5 = new Graph(50,0.2);
  vector<int> path5 = sp.path(g5, 0, 49);
  for(int i = path5.size()-1; i >= 0; --i){
    cout << path5[i] << " ";
  }
  cout << endl;
        
}

int main(){
  cout << "----------" << endl;
  test_graph_class();
  cout << "----------" << endl;
  test_shortest_path_class();
  return 0;
}
