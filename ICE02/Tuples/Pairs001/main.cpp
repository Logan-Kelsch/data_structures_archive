/*
Author: Don Spickler
Creation Date: 1/23/2024
Last Update: 1/24/2024
Description: Example of using pairs.
Pairs come in handy for many data structures like dictionaries/maps
where you have a key value pair for data. They also provide a slick way to pass
multiple values with different types from a function without the need for
reference variables or the creation of an output struct.
*/

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <typeinfo>
#include <utility> // For pair structure.
#include <vector>

using namespace std;

// Prototypes
template <class T> void printPair(T &i);
pair<double, int> getPair();

/*
Description: Simple example of returning a pair from a function.
Parameters: None
Return: Pair of integer and C string.
Notes: This needs to be above the main due to deduction sequence.
If this was prototyped and placed below the main the call to the
function would not know the data type to be used for auto and
hence produce a compile error.
*/
auto getAnotherPair() { return make_pair(42, "The answer."); }

/*
Description: Simple example of returning a pair from a function.
Parameters: None
Return: Pair of integer and C string.
Notes: This needs to be above the main due to deduction sequence.
If this was prototyped and placed below the main the call to the
function would not know the data type to be used for auto and
hence produce a compile error.
*/
auto getYetAnotherPair() {
  return make_pair(12345, "I have the same combination on my luggage!");
}

int main() {
  srand(time(0));

  // Example variable.
  pair<int, string> p;
  p = {5, "Golden Rings"};
  cout << p.first << " " << p.second << endl;

  cout << "-----" << endl;

  // Declaration of a vector of pairs.
  vector<pair<int, string>> stuff;
  stuff.push_back({5, "Golden Rings"});
  stuff.push_back({6, "Fruitcakes"});
  stuff.push_back({2, "Visa Bills"});
  stuff.push_back({4, "Hangovers"});
  stuff.push_back({2, "Cups of hot chocolate."});
  stuff.push_back({4, "Overstaying relatives."});
  stuff.push_back({4, "Gift returns."});

  // Range-based for traversing the vector.
  for (auto item : stuff)
    cout << item.first << " " << item.second << endl;

  cout << "-----" << endl;

  // Sorting of pairs, note the output.
  sort(stuff.begin(), stuff.end());

  for (auto item : stuff)
    printPair(item);

  cout << "-----" << endl;

  // Sorting using a lambda expression for the order.
  sort(stuff.begin(), stuff.end(), [](auto &x, auto &y) { return x > y; });

  for (auto item : stuff)
    printPair(item);

  cout << "-----" << endl;

  // Pair data from function return, using auto and explicit pair
  // template type.
  auto rp = getPair();
  printPair(rp);

  pair<double, int> rp2 = getPair();
  printPair(rp2);

  cout << "-----" << endl;

  // C++ 17 addition of auto decomposition.
  // a is declared to be an integer and b is a C string.
  auto [a, b] = getAnotherPair();
  cout << a << "  " << b << endl;

  // typeid can be used to determine, display, and test
  // data types.
  cout << typeid(a).name() << endl;
  cout << typeid(b).name() << endl;

  if (typeid(a) == typeid(int))
    cout << "a is an integer." << endl;

  if (typeid(b) == typeid(string))
    cout << "b is a string." << endl;

  if (typeid(b) == typeid(const char *))
    cout << "b is a C string." << endl;

  /*
  Although a and b are the correct data types for the
  return pair this syntax does not compile since the
  compiler sees [a, b] as the beginning of a lambda
  expression.

  [a, b] = getYetAnotherPair();
  */

  auto q = getYetAnotherPair();
  cout << q.first << " " << q.second << endl;
  cout << typeid(q).name() << endl;

  if (typeid(q) == typeid(pair<int, const char *>))
    cout << "b is a pair<int, const char *>." << endl;

  if (typeid(q) == typeid(pair<int, string>))
    cout << "b is a pair<int, string>." << endl;

  q = getAnotherPair();
  cout << q.first << " " << q.second << endl;

  /*
   One way around the decomposition problem above is to localize a and b, by
   blocking.  This method is not the nicest to read but I have seen it in
   professional code.  Specifically in code developed by NVidia for their
   real-time ray tracing engine. We will change the names of a and b since these
   are now global to the main.
   */

  {
    auto [f, g] = getAnotherPair();
    cout << f << " " << g << endl;
  }

  {
    auto [f, g] = getYetAnotherPair();
    cout << f << " " << g << endl;
  }

  return 0;
}

/*
Description: Prints the pair values to the console.
Parameters: i of template type.
Return: None
Notes: If the input is not a pair there will be a compile error
on the calls to first and second.
*/
template <class T> void printPair(T &i) {
  cout << i.first << " " << i.second << endl;
}

/*
Description: Gets a double and integer and returns the pair.
Parameters: None
Return: Pair of a double and integer.
Notes: In this case we do not need to use make_pair on the
return since the return type is specified.  The syntax
{d, i} actually creates an initializer list and then the
compiler casts this into a pair automatically.
*/
pair<double, int> getPair() {
  double d;
  int i;

  cout << "Input a double: ";
  cin >> d;

  cout << "Input an integer: ";
  cin >> i;

  return {d, i};
}
