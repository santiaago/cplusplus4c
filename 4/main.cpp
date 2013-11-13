// main.cpp: Santiago Arias
// Description: HW4 the HEX program
// c++11
// to compile: g++ -std=c++11 graph.cpp shortest_path.cpp main.cpp;
#include <iostream>

#include "graph.h"
#include "shortest_path.h"
#include "hex.h"

using namespace std;

int main(){
  cout << "HW 4" << endl;
  Hex hex1(7);
  hex1.display();
  cout << endl;
  Hex hex2(11);
  hex2.display();
  
}
