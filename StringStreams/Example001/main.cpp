/*
Author: Don Spickler
Creation Date: 1/27/2022
Last Update: 1/27/2022
Description: Simple example on using a stringstream.
User Interface: None
Notes: The string stream is a streaming (C++) version of the
sprintf function from C.
*/

#include <iostream>
#include <sstream>

using namespace std;

int main() {
  string str, str2;
  cout << "Input a string: ";
  getline(cin, str);

  stringstream strstm(str);

  while (strstm >> str2)
    cout << str2 << endl;

  return 0;
}
