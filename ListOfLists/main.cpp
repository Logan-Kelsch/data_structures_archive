#include <iostream>
#include <vector>

#include "ListOfLists.h"

using namespace std;

template <class T> void Print(ListOfLists<T>);
template <class T> void Print(vector<T>);

int main() {
  srand(time(0));

  ListOfLists<int> L1(7, 7);

  L1[0] = {0, 1, 1, 0, 1, 0, 1};
  L1[1] = {0, 1, 0, 1, 1, 0, 0};
  L1[2] = {1, 1, 0, 0, 0, 1, 1};
  L1[3] = {0, 0, 0, 0, 0, 1, 1};
  L1[4] = {1, 0, 0, 1, 0, 1, 0};
  L1[5] = {1, 0, 0, 0, 1, 0, 0};
  L1[6] = {0, 1, 0, 1, 0, 0, 0};

  Print(L1);
  cout << endl;

  L1[2][5] = 17;

  Print(L1);
  cout << endl;

  cout << L1[4][1] << endl;
  cout << L1[2][0] << endl;

  auto v = L1[2];
  Print(v);
  cout << endl;
  cout << endl;

  ListOfLists<int> L2(10, 5);
  for (size_t i = 0; i < L2.size(); i++)
    for (size_t j = 0; j < L2[i].size(); j++)
      L2[i][j] = rand() % 100;

  Print(L2);
  cout << endl;

  return 0;
}

template <class T> void Print(ListOfLists<T> L) {
  if (L.size() == 0)
    return;

  for (size_t i = 0; i < L.size(); i++) {
    for (size_t j = 0; j < L[i].size(); j++)
      cout << L[i][j] << " ";
    cout << endl;
  }
}

template <class T> void Print(vector<T> V) {
  if (V.size() == 0)
    return;

  for (size_t j = 0; j < V.size(); j++)
    cout << V[j] << " ";
}
