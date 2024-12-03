/*
 Author: Don Spickler
 Creation Date: 1/28/2022
 Last Update: 2/10/2024
 Description: Testing program that shows some functionality of the vector and
 iterators.
 User Interface: None
 */

#include <algorithm> // Required for STL algorithms
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random> // For the random number generator in shuffle.
#include <vector>

using namespace std;

// Prototypes
template <class T> void print(vector<T> const &vect, bool nl = false);
template <class T> void printSizeCap(vector<T> const &vect);
void div(string s = "");

int main() {
  srand(time(0));

  div("Creation of a vector and an iterator, and insert.");

  vector<int> vect;
  vector<int>::iterator vectIter;

  for (int i = 0; i < 10; i++)
    vect.push_back(i + 1);

  print(vect);

  vect.insert(vect.begin() + 5, 123);

  print(vect);

  div("Removing elements.");

  vect.erase(vect.begin() + 8);
  print(vect);

  vect.erase(vect.begin() + 3, vect.end() - 2);
  print(vect);

  div("Shuffling with random_shuffle");

  for (int i = 0; i < 20; i++)
    vect.push_back(rand() % 100);

  // Algorithms random_shuffle method.  This is actually deprecated and
  // should be replaced with the shuffle function.  There is an example
  // below.
  print(vect);
  random_shuffle(vect.begin(), vect.end());
  print(vect);
  random_shuffle(vect.begin(), vect.end());
  print(vect);

  div("Shuffling with random");

  // To replace the random_shuffle with shuffle you need to include a
  // random number generator device.  This is an extra step but is not too
  // difficult to implement.  Include the random library at the top.
  // Define a random device and then construct a generator using the
  // random device.  This generator is the third parameter in the shuffle
  // function, the first two are your iterators.
  random_device rd;
  mt19937 gen(rd());

  sort(vect.begin(), vect.end());
  print(vect);
  shuffle(vect.begin(), vect.end(), gen);
  print(vect);
  shuffle(vect.begin(), vect.end(), gen);
  print(vect);

  div("Sorting");

  // Sorting
  sort(vect.begin(), vect.end());
  print(vect);

  vectIter = vect.begin();
  while (vectIter < vect.end()) {
    cout << *vectIter << "  ";
    vectIter++;
  }
  cout << endl;

  cout << "End Program" << endl;

  return 0;
}

/*
 Description: Print a vector of any data type, as long as the data type can be
 streamed. Parameters: vect - Vector to be printed to the console screen. nl -
 boolean that flags if there should be a line feed after each print. Return:
 None
 */

template <class T> void print(vector<T> const &vect, bool nl) {
  for (unsigned long i = 0; i < vect.size(); i++) {
    cout << vect[i] << " ";
    if (nl)
      cout << endl;
  }

  if (!nl)
    cout << endl;
}

/*
 Description: Prints the size and capacity the vector.
 Parameters: vect - Vector to use to print the size and capacity.
 Return: None
 */

template <class T> void printSizeCap(vector<T> const &vect) {
  cout << vect.size() << "  " << vect.capacity() << endl;
}

/*
 Description: Prints a dividing line.
 Parameters: String s to be printed.
 Return: None
 */

void div(string s) {
  cout << endl << "---------------------- " << s << endl << endl;
}
