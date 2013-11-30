#ifndef HEX_H

#define HEX_H

#include <iostream>
#include "graph.h"

using namespace std;

// Hex class
class Hex{
 public:
  Hex();//:board_size(7){}
  Hex(int size);//:board_size(size){}
  void display();
 private:
  void build_hex_graph();
  int board_size;
  Graph game;
};
#endif // HEX_H
