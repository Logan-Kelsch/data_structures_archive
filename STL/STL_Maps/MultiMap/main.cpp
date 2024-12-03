/*
Author: Don Spickler
Creation Date: 2/10/2024
Last Update: 2/10/2024
Description: Simple example of using the STL multimap.
*/

#include <iostream>
#include <map>

using namespace std;

template <class T, class U> void PrintMap(multimap<T, U> M) {
  for (auto it = M.begin(); it != M.end(); it++) {
    cout << it->first << " " << it->second << endl;
  }
}

int main() {
  multimap<int, string> M;
  multimap<int, string>::iterator start, end;

  M.insert(make_pair(9, "Dan"));
  M.insert(make_pair(7, "John"));
  M.insert(make_pair(7, "Kim"));
  M.insert(make_pair(4, "Anna"));
  M.insert(make_pair(9, "Don"));
  M.insert(make_pair(15, "HAL"));
  M.insert(make_pair(9, "Dave"));
  M.insert(make_pair(4, "Jacob"));
  M.insert(make_pair(7, "Jane"));

  PrintMap(M);

  start = M.lower_bound(7);
  end = M.upper_bound(7);

  cout << endl;
  for (multimap<int, string>::iterator it = start; it != end; it++)
    cout << it->first << " " << it->second << endl;

  cout << endl;

  // auto p = M.equal_range(9);
  pair<multimap<int, string>::iterator, multimap<int, string>::iterator> p =
      M.equal_range(9);

  for (multimap<int, string>::iterator it = p.first; it != p.second; it++)
    cout << it->first << " " << it->second << endl;

  return 0;
}
