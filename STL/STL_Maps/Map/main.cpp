/*
Author: Don Spickler
Creation Date: 2/10/2024
Last Update: 2/10/2024
Description: Simple driver function for STL map usage.
User Interface: None
Notes: None
*/

#include <algorithm>
#include <iostream>
#include <map>

#include "Die.h"

using namespace std;

void div(string s = "") { cout << "\n------------------- " << s << "\n\n"; }

template <class T, class U> void PrintMap(map<T, U> M);

int main() {
  div("Map with integer key and string value.");

  // Definition for a (key, value) pair. New keys allocate new objects,
  // repeated keys overwrite the old associated value.
  map<int, string> M;
  M[1] = "Hello";
  M[2] = "World";

  PrintMap(M);

  cout << endl;
  M[5] = "John Doe";

  PrintMap(M);

  cout << endl;
  M[2] = "Friend";

  // Accessing the entire (key, value) pair can be done with an iterator.
  // Note that the data type being used for the (key, value) pair is a
  // pair.
  cout << endl;
  map<int, string>::iterator mapit = M.begin();
  pair<int, string> elt = *mapit;
  cout << elt.first << " " << elt.second << endl;
  mapit++;
  elt = *mapit;
  cout << elt.first << " " << elt.second << endl;
  cout << mapit->first << " " << mapit->second << endl;
  cout << endl;

  PrintMap(M);

  div("Map with string key and double value.");

  const double PI = 3.141592653589;
  map<string, double> Numbers;
  Numbers["pi"] = PI;
  Numbers["2pi"] = 2 * PI;
  Numbers["3pi"] = 3 * PI;

  PrintMap(Numbers);
  cout << endl;

  Numbers["e"] = 2.718281828459045;
  PrintMap(Numbers);
  cout << endl;

  // Iterators are returned from some methods, e.g. the find searching
  // function. If the iterator is equal to the end then the search failed.
  map<string, double>::iterator iter = Numbers.find("e");
  if (iter != Numbers.end()) {
    cout << "Item Found" << endl;
    cout << iter->first << " " << iter->second << endl;
  } else
    cout << "Item Not Found" << endl;

  cout << endl;
  map<string, double>::iterator iter2 = Numbers.find("Golden Ratio");
  if (iter2 != Numbers.end()) {
    cout << "Item Found" << endl;
    cout << iter2->first << " " << iter2->second << endl;
  } else
    cout << "Item Not Found" << endl;

  PrintMap(Numbers);
  cout << endl;

  cout << Numbers["Golden Ratio"] << endl << endl;
  PrintMap(Numbers);
  cout << endl;

  Numbers.erase("pi");
  PrintMap(Numbers);
  cout << endl;

  Numbers["Golden Ratio"] = 1.618033988749895;

  PrintMap(Numbers);
  cout << endl;

  div("Map with int key and Die object value.");

  map<int, Die> Dice;
  Dice[1] = Die(5);
  Dice[3] = Die(7);
  Dice[-4] = Die(12);
  Dice[8] = Die(20);

  PrintMap(Dice);
  cout << endl;

  for (int i = 10; i < 100; i++)
    Dice[i] = Die(i);

  PrintMap(Dice);

  div("Map with double key and double value.");

  map<double, double> D;
  for (int i = 1; i <= 20; i++)
    D[1.0 * rand() / RAND_MAX] = i * PI;

  PrintMap(D);

  div("Map with Die key and int object value.");

  map<Die, int> Dice2;
  for (int i = 1; i <= 20; i++) {
    Die d(i);
    Dice2[d] = rand();
  }

  PrintMap(Dice2);

  return 0;
}

/*
Description: Prints the map to the console.
Parameters: Templated map object M.
Return: None
Notes: Assumed that the first and second data types are streamable.
*/
template <class T, class U> void PrintMap(map<T, U> M) {
  for (auto it = M.begin(); it != M.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }
}
