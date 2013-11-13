#ifndef HEX_H

#define HEX_H

#include <iostream>

using namespace std;

// Hex class
class Hex{
 public:
 Hex():board_size(7){}
 Hex(int size):board_size(size){}
  void display();
 private:
  int board_size;
};
#endif // HEX_H
