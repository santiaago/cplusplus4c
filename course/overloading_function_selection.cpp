// overloading_function_selection.cpp: Santiago Arias
// Description: Some examples of section 4.5

#include <iostream>
#include "math.h"

using namespace std;

// simple class point
class point{
public:
  point():x(0.0), y(0.0){}
  // if we set explicit here we cannot do implicit convertions.
  // e.g: double d(point); or point = d;
  explicit point(double u): x(u), y(0.0){} 
  // by overloading double operator and keeping the explicit keyword
  // we still can do double e(d);
  operator double(){
    return sqrt(x*x + y*y);
  }
  // use friend to allow it access priviledges and unlike a class method
  // it does not have a dot argument. e.g cout << point ;
  friend ostream& operator<<(ostream& out, point p);
private:
  double x,y;
};

ostream& operator<<(ostream& out, point p){
  out << "(" << p.x << "," << p.y << ")";
  return out;
}

int main(){
  point s;
  double d = 3.5;
  //s = d; // implicit
  double e(s);
  cout << "point: " << s << endl;
  s = static_cast<point>(d);// explicit
  cout << "point: " << s << endl;
}
