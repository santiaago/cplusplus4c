// graph.cpp: Santiago Arias
// Description: Graph ATD

#include <iostream> // std::cout, std::endl
#include <vector>
#include <queue>
#include <stack>

#include "graph.h"
#include "shortest_path.h"

const int kSampleSize = 10000; // sample size to compute average of cost path

int main(){
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
