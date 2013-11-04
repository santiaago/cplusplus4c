// generics-2-1.cpp: Santiago Arias
// Description: Simple generic example

#include <iostream>

using namespace std;

template<class T>
T sum(const T data[], int size, T s=0){
  T asum = 0;
  for(int i = 0; i < size; ++i){
    asum += data[i];
  }
  return asum;
}


template<class T>
T rem(const T data[], int size, T s=0){
  T asum = 0;
  for(int i = 0; i < size; ++i){
    asum -= data[i];
  }
  return asum;
}


int main(){
  cout << "template sum()" << endl;

  int a[] = {1,2,3};
  double b[] = {2.1, 2.2, 2.3};
  cout << sum(a, 3) << endl;
  cout << sum(b, 3) << endl;
  cout << rem(a, 3) << endl;
  cout << rem(b, 3) << endl;
}
