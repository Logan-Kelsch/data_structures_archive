/*
Author: Don Spickler
Creation Date: 1/27/2022
Last Update: 1/27/2022
Description: Simple use of a stringstream to act like cout to a string-like
container.
User Interface: None
Notes: None
*/

#include <cmath>
#include <iostream>
#include <sstream>

using namespace std;

int main() {
  stringstream strstream;
  const double EAPPROX = 2.7182818284589045;

  strstream << "Hello world: "
            << "there are " << 14 << " lines in a sonnet.\n";
  strstream << "pi = " << atan(1) * 4 << "\n";
  strstream << "e = " << EAPPROX << endl;

  cout << strstream.str();

  return 0;
}
