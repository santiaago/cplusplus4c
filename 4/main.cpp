// main.cpp: Santiago Arias
// Description: HW4 the HEX program
// c++11
// to compile: g++ -std=c++11 graph.cpp shortest_path.cpp main.cpp;
#include <iostream>

#include "graph.h"
#include "shortest_path.h"

using namespace std;

int main(){
  cout << "HW 4" << endl;
  int size = 7;

  string space =  "";
  for(int j = 0; j < 7; j++){
    cout << space;
    for(int i = 0; i < 7; i++){
      cout << " . ";
      if(i != 6)
	cout << " - ";
    }
    cout << endl;
    if(j != 6){
      space += " ";
      cout << space;
      cout << " \\ ";
      for(int i = 0; i < 6; i++){
	cout << "  / " << "\\ ";
      }
      cout << endl;
      space += " ";
    }
  }
  cout << endl << endl;
// .  -  .  -  .  -  .  -  .
//  \   / \ 

}
