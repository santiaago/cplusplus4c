// output_random_graph.cpp: Santiago Arias
// Description: Output random graph example

#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

double prob(){
  return (static_cast<double>(rand())/RAND_MAX);
}

int main(){

  for(int i  = 0; i < 10; i++)
    cout << prob() << " ";
  cout << endl;

  int size = 15;
  double density;
  cout << "graph size?" << endl;
  cin >> size;

  cout << "graph density (0, 1)?" << endl;
  cin >> density;

  bool** graph;
  int** color;
  int** cost;
  srand(time(0)); // seed of random number generator
  
  // initialize the 3 matrices
  graph = new bool*[size];
  color = new int*[size];
  cost = new int*[size];

  for(int i = 0; i < size; ++i){
    graph[i] = new bool[size];
    color[i] = new int[size];
    cost[i] = new int[size];
  }

  // generate undirected edges
  for(int i = 0; i < size; ++i){
    for(int j = i; j < size; ++j){
      if(i == j)
	graph[i][j] = false;//no loops
      else
	graph[i][j] = graph[j][i] = (prob() < density);
    }
  }

  // generate cost and colors
  for(int i = 0; i < size; ++i){
    for(int j = i; j < size; ++j){
      if(graph[i][j]){
	color[i][j] = color[j][i] = rand()%3;
	cost[i][j] = cost[j][i] = prob()*30;
      }
    }
  }

  //
  ofstream outp("graph_data");
  outp << size << "\n";
  for(int i = 0; i < size; ++i){
    for(int j = 0; j < size; ++j){
      if(graph[i][j]){
	outp << i << '\t' << j << '\t' << cost[i][j] << '\t' << color[i][j] << '\n';
      }
    }
  }

}
