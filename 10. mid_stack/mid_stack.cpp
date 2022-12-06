#include <iostream>
#include "SHAKIB_STACK.h"
using namespace std;

class person
{
public:
  string name;
  int age;
  person()
  {
    this->age = -1;
    this->name = "";
  }
  person(string name, int age)
  {
    this->age = age;
    this->name = name;
  }
};

int main()
{
  Stack<person> st;
  person shakib("shakib", 22);
  person tabib("tabib", 10);
  person tuhi("tuhi", 7);
  person kutta("kutta", 7);
  st.push(shakib);
  st.push(tabib);
  st.push(tuhi);
  st.push(kutta);
  // st.push();
  // st.push();
  // st.push();
  st.pop();
  cout << st.mid().name << endl;
  return 0;
}