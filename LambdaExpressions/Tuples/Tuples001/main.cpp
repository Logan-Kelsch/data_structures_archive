/*
Author: Don Spickler
Creation Date: 1/23/2024
Last Update: 1/24/2024
Description: Example of using tuples.
Tuples are very useful as a generalization of the pair construct, but
a bit harder to work with.  They also provide a slick way to pass multiple
values with different types from a function without the need for
reference variables or the creation of an output struct.
*/

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <tuple> // For tuple structure.
#include <typeinfo>
#include <utility> // For pair structure.
#include <vector>

using namespace std;

/*
Description: General tuple printing function.
Parameters: tp a tuple.
Return: None
Notes: Several advanced techniques being used here and this is
just for your information.  Taken in part from Stack Overflow
discussions.
*/
void printTuple(const auto &tp) {
  apply([](const auto &...e) { ((cout << e << " "), ...); }, tp);
  cout << '\n';
}

/*
Description: Example of returning a tuple from a function.
Parameters: a, b integers.
Return: Tuple of two ints and a double.
Notes: Since the return type is explicitly defined this function
could be prototyped and place below the main.
*/
tuple<int, int, double> fct1(int a, int b) {
  double d = 1.0 * a / b;
  return make_tuple(a, b, d);
}

/*
Description: Example of returning a tuple from a function.
Parameters: a, b integers.
Return: Tuple of two ints and a double.
Notes: Since the return type is explicitly defined this function
could be prototyped and place below the main. In addition, we
do not need the make_tuple here since the explicit return type
will be cast from the initializer list.
*/
tuple<int, int, double> fct2(int a, int b) {
  double d = 1.0 * a / b;
  return {a, b, d};
}

/*
Description: Example of returning a tuple from a function.
Parameters: a, b integers.
Return: Tuple of two ints and a double.
Notes: Since the return type is auto we nee this declaration
above the calls and the make_tuple must be used to create a
tuple.
*/
auto fct3(int a, int b) {
  double d = 1.0 * a / b;
  return make_tuple(a, b, d);
}

int main() {
  srand(time(0));

  tuple<int, string, bool> tup1(16, "Test", true);

  // get statement to extract the components of the tuple.
  // Note that the value inside the <> must be a constant.
  cout << "tup1 = (" << get<0>(tup1) << ", " << get<1>(tup1) << ", "
       << get<2>(tup1) << ")" << endl;

  cout << get<0>(tup1) << endl;
  const int POS = 1;
  cout << get<POS>(tup1) << endl;

  // Compile error, pos is not constant.
  //   int pos = 1;
  //   cout << get<pos>(tup1) << endl;

  // Get number of components of that tuple.
  // The decltype statement returns the data type
  // of the parameter variable.
  cout << tuple_size<decltype(tup1)>::value << endl;

  double a = 7.345;
  cout << typeid(a).name() << endl;
  decltype(a) b = 3.14159; // b is the same data type as a.
  cout << typeid(b).name() << endl;

  /*
  This also means that the following loop cannot
  traverse the components of a tuple since C++ does
  not include compile-time constant loops. There are ways
  to do this but require more advanced constructs like
  variadic templates or apply statements.

  for (int i = 0; i < tuple_size<decltype(tup1)>::value; i++){
    cout << get<i>(tup1) << endl;
  }
  */

  cout << "-----" << endl;

  cout << typeid(get<0>(tup1)).name() << endl;
  cout << typeid(get<1>(tup1)).name() << endl;
  cout << typeid(get<2>(tup1)).name() << endl;

  if (typeid(get<2>(tup1)) == typeid(bool))
    cout << "Type #2 is a boolean." << endl;

  if (typeid(get<0>(tup1)) == typeid(bool))
    cout << "Type #0 is a boolean." << endl;

  if (typeid(get<0>(tup1)) == typeid(int))
    cout << "Type #0 is an integer." << endl;

  cout << "-----" << endl;

  // Using statement to define an alias for the tuple
  // data type.  Also a way to get the number of components
  // to the tuple.
  using tuptype = tuple<int, string, bool>;
  cout << tuple_size<tuptype>::value << endl;

  cout << "-----" << endl;

  // C++ 17 auto decomposition and a tuple function return.
  // x and y are integers and z is a double.
  auto r = fct1(17, 3);
  auto [x, y, z] = r;
  cout << x << " " << y << " " << z << endl;

  // Note that the same blocking trick will allow multiple
  // decompositions with the same variable names.  Again,
  // not the best structure.
  {
    auto [x2, y2, z2] = fct1(17, 3);
    cout << x2 << " " << y2 << " " << z2 << endl;
  }

  {
    auto [x2, y2, z2] = fct2(17, 3);
    cout << x2 << " " << y2 << " " << z2 << endl;
  }

  {
    auto [x2, y2, z2] = fct3(17, 3);
    cout << x2 << " " << y2 << " " << z2 << endl;
  }

  cout << "-----" << endl;

  // Call to a general tuple printer function.
  // Uses apply on a lambda expression.
  printTuple(tup1);

  return 0;
}
