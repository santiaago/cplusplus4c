// forward_iterator.cpp: Santiago Arias
// Description: Forward iterator example

#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

template<typename ForwardIterator>
void square(ForwardIterator first, ForwardIterator last){
  for(;first !=last; first++){
    *first = (*first) * (*first);
  }
}

int main(){
    vector<int> data {1,2,3,4,5,6};
    square(data.begin(), data.end());
    for(auto i : data){
      cout << i << " ";
    }
    cout << endl;
}
