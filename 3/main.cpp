// main.cpp: Santiago Arias
// Description: Prim algorithm
// c++11
// to compile: g++ -std=c++11 graph.cpp shortest_path.cpp main.cpp;
#include <iostream>

#include "graph.h"
#include "shortest_path.h"

using namespace std;

int main(){
  cout << "HW 3" << endl;
  Graph *g = new Graph("sample_data");// path to sample data
  ShortestPath sp;
  sp.prim(g);
}
