/*
 Author: Don Spickler
 Creation Date: 1/28/2022
 Last Update: 1/28/2022
 Description: Testing program that shows some functionality of the array and
 iterators. User Interface: None
 */

#include <algorithm> // Required for STL algorithms
#include <array>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include <random> // For the random number generator in shuffle.

using namespace std;

// Prototypes
template <class T, long unsigned int s>
void print(array<T, s> const &A, bool nl = false);

template <class T, long unsigned int s>
void print2(array<T, s> const &A, bool nl = false);

void div();

int main() {
  srand(time(0));

  // Note that the STL array also includes a template Parameters
  // that designates the size of the array.  Unlike the vector
  // the array cannot be resized. It also uses iterators in place of
  // the pointer.
  array<int, 10> arr;
  array<int, 10>::iterator arrIter;

  for (int i = 0; i < 10; i++)
    arr[i] = i + 1;

  print(arr);

  div();

  // Algorithms random_shuffle method.  This is actually deprecated and
  // should be replaced with the shuffle function.  There is an example
  // below.
  print(arr);
  random_shuffle(arr.begin(), arr.end());
  print(arr);
  random_shuffle(arr.begin(), arr.end());
  print(arr);

  div();

  // To replace the random_shuffle with shuffle you need to include a
  // random number generator device.  This is an extra step but is not too
  // difficult to implement.  Include the random library at the top.
  // Define a random device and then construct a generator using the
  // random device.  This generator is the third parameter in the shuffle
  // function, the first two are your iterators.
  random_device rd;
  mt19937 gen(rd());

  sort(arr.begin(), arr.end());
  print(arr);
  shuffle(arr.begin(), arr.end(), gen);
  print(arr);
  shuffle(arr.begin(), arr.end(), gen);
  print(arr);

  div();

  sort(arr.begin(), arr.end());
  print2(arr);

  arrIter = arr.begin();
  while (arrIter < arr.end()) {
    cout << *arrIter << "  ";
    arrIter++;
  }
  cout << endl;

  cout << "End Program" << endl;

  return 0;
}

/*
 Description: Print an array of any data type, as long as the data type can be
 streamed.
 Parameters: A - Array to be printed to the console screen.
 nl - boolean that flags if there should be a line feed after each print.
 Return: None
 */
template <class T, long unsigned int s>
void print(array<T, s> const &A, bool nl) {
  for (int i = 0; i < A.size(); i++) {
    cout << A[i] << " ";
    if (nl)
      cout << endl;
  }

  if (!nl)
    cout << endl;
}

/*
 Description: Print an array of any data type, as long as the data type can be
 streamed. Since an array has a begin and end iterator that is part of the
 class structure we can use a range-based for loop on it, like the vector.
 Parameters: A - Array to be printed to the console screen.
 nl - boolean that flags if there should be a line feed after each print.
 Return: None
 */
template <class T, long unsigned int s>
void print2(array<T, s> const &A, bool nl) {
  for (T item : A) {
    cout << item << " ";
    if (nl)
      cout << endl;
  }

  if (!nl)
    cout << endl;
}

/*
 Description: Prints a dividing line.
 Parameters: None
 Return: None
 */

void div() {
  cout << endl << "----------------------------------" << endl << endl;
}
