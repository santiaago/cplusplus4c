// priority_queues.cpp: Santiago Arias
// Description: Example of usage
#include <iostream>
#include <queue>
#include <string>

using namespace std;

void demo1(){
  cout << "demo1" << endl;
  priority_queue<string> pq_string;

  pq_string.push("hello");
  pq_string.push("world");
  pq_string.push("priority");
  pq_string.push("queue");
  
  while(!pq_string.empty()){
    cout << pq_string.top() << endl; // prints highest priority string
    pq_string.pop(); // removes highest priority string
  }
  cout << endl;
}

class mycomparison{
  bool reverse;
public:
  mycomparison(const bool & revparam = false): reverse(revparam){}
  bool operator() (const int& lhs, const int& rhs){
    if(reverse){
      return (lhs>rhs);
    }
    return (lhs<rhs);
  }
};

void demo2(){
  cout << "demo2" << endl;

  typedef priority_queue<int, vector<int>, mycomparison> pq_compare;
  cout << "test 1" << endl;
  pq_compare pq_test;
  pq_test.push(10);
  pq_test.push(60);
  pq_test.push(50);
  pq_test.push(20);

  while(!pq_test.empty()){
    cout << pq_test.top() << endl; // prints highest priority string
    pq_test.pop(); // removes highest priority string
  }
  cout << endl;
  cout << "test 2"<< endl;
  pq_compare pq_test2(true);
  pq_test2.push(10);
  pq_test2.push(60);
  pq_test2.push(50);
  pq_test2.push(20);

  while(!pq_test2.empty()){
    cout << pq_test2.top() << endl; // prints highest priority string
    pq_test2.pop(); // removes highest priority string
  }

  cout << endl;

}

int main(){
  cout << "priority queues demos" << endl;
  demo1();
  demo2();
}
