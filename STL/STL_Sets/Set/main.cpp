/*
Author: Don Spickler
Creation Date: 2/10/2024
Last Update: 2/10/2024
Description: Simple example of use of sets.
User Interface: None
Notes: None
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std;

void div(string s = "") {
  cout << "\n----------------- " << s << "\n\n";
}

template <class T> void PrintSet(set<T> M) {
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

    div("Set creation and inserting elements.");

    set<int> S = {1, 2, 3, 4, 5};
    S.insert(7);
    S.insert(7);
    S.insert(5);

    PrintSet(S);

    for (int i = -4; i < 10; i++)
        S.insert(i);

    PrintSet(S);

    div("Set operations.");

    cout << S.size() << endl;
    cout << S.empty() << endl;
    S.clear();
    cout << S.empty() << endl;

    div("More inserts, note order and content.");

    for (int i = 0; i < 10; i++) {
        int val = rand() % 20;
        cout << val << " ";
        S.insert(val);
    }

    cout << endl;
    PrintSet(S);

    div("Set iterators and find function.");

    // If the find returns the end of the set the search has failed.
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

    div("Using iterators.");

    pos = S.begin();
    while (pos != S.end())
        cout << *pos++ << " ";
    cout << endl;

    div("More on insert and assignment.");

    S.clear();
    int A[10];

    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        cout << val << " ";
        A[i] = val;
    }

    set<int> T;
    T.insert({4, 5, 6, 7});
    PrintSet(T);

    // Assignment, deep copy.
    S = T;
    PrintSet(S);

    T.insert({10, 3, 7, 11});
    PrintSet(T);
    PrintSet(S);

    T.insert(A, A + 10);
	PrintSet(T);

	S.clear();
	S.insert(++T.begin(), --T.end());
	PrintSet(S);

    div("Inserting from a vector, iterators again.");

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
