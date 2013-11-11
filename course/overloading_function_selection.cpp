// overloading_function_selection.cpp: Santiago Arias
// Description: Some examples of section 4.5

#include <iostream>
#include "math.h"

using namespace std;

// simple class point
class point{
public:
  point():x(0.0), y(0.0){}
  point(double u, double v): x(u), y(v){}
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
  // overload binary plus using a member function
  // a = b + c // b.operator+(c)
  // point operator+(point p){
  //   return point(x+p.x, y + p.y);
  // }
  // overload as a friend function
  //a = b + c // operator+(b, c);
  friend point operator+(const point& p1, const point& p2);
private:
  double x,y;
};

ostream& operator<<(ostream& out, point p){
  out << "(" << p.x << "," << p.y << ")";
  return out;
}

point operator+(const point& p1, const point& p2){
  return point(p1.x + p2.x, p1.y + p2.y);
}

int main(){
  point s;
  double d = 3.5;
  //s = d; // implicit
  double e(s);
  cout << "point: " << s << endl;
  s = static_cast<point>(d);// explicit
  cout << "point: " << s << endl;
  point a(1,2);
  point b(2,1);
  point c = a + b;
  point p = a + b + c;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;
  cout << p << endl;
}
