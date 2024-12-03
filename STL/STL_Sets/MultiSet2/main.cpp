/*
Author: Don Spickler
Creation Date: 2/10/2024
Last Update: 2/10/2024
Description: Since the multiset automatically sorts values it could be used
to sort an array or vector.  This example times this technique against the
algorithm sort function.
User Interface: Input of array (vector) size.
Notes: None
*/

#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
using namespace std::chrono;

int main() {
  // Size of the array to be tested.
  int size;
  cout << "Input size: ";
  cin >> size;

  // Create objects.
  multiset<int> S;
  vector<int> V;

  // Populate random vector.
  for (int i = 0; i < size; i++)
    V.push_back(rand() % size);

  // Time the use of the multiset.  Insert into multiset, then repopulate
  // the vector.
  high_resolution_clock::time_point t1 = high_resolution_clock::now();
  S.insert(V.begin(), V.end());

  V.clear();
  for (auto a : S)
    V.push_back(a);

  high_resolution_clock::time_point t2 = high_resolution_clock::now();
  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
  cout << "Time to sort using a multiset: " << time_span.count() << " seconds."
       << endl;

  // Repopulate Vector
  for (int i = 0; i < size; i++)
    V.push_back(rand() % size);

  // Time the sort function.
  t1 = high_resolution_clock::now();

  sort(V.begin(), V.end());

  t2 = high_resolution_clock::now();
  time_span = duration_cast<duration<double>>(t2 - t1);
  cout << "Time to sort using sort: " << time_span.count() << " seconds."
       << endl;

  return 0;
}
