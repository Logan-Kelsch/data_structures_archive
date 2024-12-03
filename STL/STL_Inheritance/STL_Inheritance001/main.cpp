/*
Author: Don Spickler
Creation Date: 2/10/2024
Last Update: 2/10/2024
Description: Simple driver program to demonstrate the STL inherited class.
User Interface: None
Notes: None
*/

#include <iostream>

#include "MathVec.h"

using namespace std;

int main() {
  MathVec<double> v1, v2, v3;

  v1.push_back(2.3);
  v1.push_back(4.9);
  v1.push_back(-1.8);
  v1.push_back(7);

  v2.push_back(3.9);
  v2.push_back(7.6);
  v2.push_back(9.9);
  v2.push_back(-2.8);

  v3 = v1 + v2;

  cout << v1 << endl;
  cout << v2 << endl;
  cout << v3 << endl;
  cout << "\n-----------------\n\n";

  v3 = v1 - v2;

  cout << v1 << endl;
  cout << v2 << endl;
  cout << v3 << endl;
  cout << v1 * v2 << endl;

  return 0;
}
