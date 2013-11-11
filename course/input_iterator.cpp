// input_iterator.cpp: Santiago Arias
// Description: example of input iterator

#include <iostream>
#include <fstream> // ifstream
#include <iterator> // istream_iterator
#include <numeric> // accumulate

using namespace std;

int main(){
  ifstream myin("text");
  istream_iterator<int> in(myin); 
  istream_iterator<int> eos; // <=> end
  // iterate once, in one direction: weakest iterator
  cout << "sum of data is: "
       << accumulate(in, eos, 0) 
       << endl; // start counting at 0

}
