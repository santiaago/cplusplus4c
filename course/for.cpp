// for.cpp: Santiago Arias
// Description: For c+++11 idioms

#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> data {1,2,3,4,5,6};
  cout << "for(auto v : data)" << endl << endl;
  for(auto v : data){
    cout << v << " ";
  }
  cout << endl << endl;;

  cout << "for(int i : data){" << endl << endl;
  for(int i : data){
    cout << i << " ";
  }
  cout << endl << endl;

  cout << "for(auto & element : data){" << endl;
  cout <<"    element += 2;" << endl;
  cout <<"  }" << endl << endl;
  
  for(auto & element : data){
    element += 2;
  }
  for(auto v : data){
    cout << v << " " ;
  }
  cout << endl << endl;
}
