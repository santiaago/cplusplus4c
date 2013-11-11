// input_file.cpp: Santiago Arias
// Description: STL input file examples

#include <iostream>
#include <fstream> // file
#include <algorithm>
#include <vector> // container

using namespace std;

// get word
// string t: where we output the word
// in: output from an input stream
// notes: 
// dont call it by value: avoid copy operation
void getw(string& t, ifstream& in){
  in >> t;
}

// read a string:
// reading from input file 'in'
// fill vector with each word from input file stream
// return the number of words when finished
int read_string(vector<string> &word, ifstream& in){
  int i = 0;
  while(!in.eof()){
    getw(word[i++], in);
  }
  return i-1;
}

int main(){

  ifstream in("text"); // constructor

  vector<string> w(1000);

  int how_many = read_string(w, in);

  w.resize(how_many);

  sort(w.begin(), w.end());

  for(auto str : w){
    cout << str << "\t";
  }
  cout << endl;
}
