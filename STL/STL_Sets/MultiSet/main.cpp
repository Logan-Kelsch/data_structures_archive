/*
Author: Don Spickler
Creation Date: 2/10/2024
Last Update: 2/10/2024
Description: Simple example of use of multisets.
User Interface: None
Notes: None
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

void div(string s = "") {
  cout << "\n--------------------------- " << s << "\n\n";
}

template <class T> void PrintSet(multiset<T> M) {
  for (T a : M) {
    cout << a << " ";
  }
  cout << endl;
}

template <class T> void PrintVector(vector<T> M) {
  for (T a : M) {
    cout << a << " ";
  }
  cout << endl;
}

int main() {
  div("Multiset Creation and Population");

  multiset<int> S = {1, 2, 3, 4, 5};
  S.insert(7);
  S.insert(7);
  S.insert(5);

  // Note the output order.
  PrintSet(S);

  for (int i = -4; i < 10; i++)
    S.insert(i);

  PrintSet(S);

  div("Multiset Operations");

  cout << S.size() << endl;
  cout << S.empty() << endl;
  S.clear();
  cout << S.empty() << endl;

  div("More insertion, note order again.");

  for (int i = 0; i < 10; i++) {
    int val = rand() % 20;
    cout << val << " ";
    S.insert(val);
  }

  cout << endl;
  PrintSet(S);

  div("Searching a multiset, as usual with the STL, uses iterators.");

  S.insert({2, 5, 4, 7});
  PrintSet(S);

  set<int>::iterator pos;
  pos = S.find(7);
  if (pos != S.end())
    cout << "7 was found" << endl;
  else
    cout << "7 was not found" << endl;

  pos = S.find(12345);
  if (pos != S.end())
    cout << "12345 was found" << endl;
  else
    cout << "12345 was not found" << endl;

  div("Standard begin and end iterators. ");

  // Note the use of != and not a < check.
  pos = S.begin();
  while (pos != S.end())
    cout << *pos++ << " ";
  cout << endl;

  div("Assignment and more insertion options. ");

  S.clear();
  int A[10];

  // Populate array A
  for (int i = 0; i < 10; i++) {
    int val = rand() % 100;
    cout << val << " ";
    A[i] = val;
  }

  multiset<int> T;
  T.insert({4, 5, 6, 7});
  PrintSet(T);

  // Assignment, deep copy.
  S = T;
  PrintSet(S);

  T.insert({10, 3, 7, 11});
  PrintSet(T);
  PrintSet(S);

  // Inserting array elements using pointers.
  T.insert(A, A + 10);
  PrintSet(T);

  // Insertion from one multiset to another.
  S.clear();
  S.insert(++T.begin(), --T.end());
  PrintSet(S);

  div("Insertion into multiset from vector, iterators again.");

  vector<int> V;

  for (int i = 0; i < 20; i++) {
    V.push_back(rand() % 25);
  }

  PrintVector(V);
  S.clear();
  S.insert(V.begin(), V.end());
  PrintSet(S);

  return 0;
}
