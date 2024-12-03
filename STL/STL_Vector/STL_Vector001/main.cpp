/*
 Author: Don Spickler
 Creation Date: 1/28/2022
 Last Update: 2/10/2024
 Description: Testing program that shows the way a vector automatically resizes.
 User Interface: None
 */

#include <iostream>
#include <vector> // Include the vector header

using namespace std;

int main() {
  // Vector Creation.
  vector<int> vect;

  // Example of the auto resizing of the vector.
  cout << "Start" << endl;
  cout << "vect size = " << vect.size() << endl;
  cout << "vect capacity = " << vect.capacity() << endl;

  cout << endl << "Add 1" << endl;
  vect.push_back(1);
  cout << "vect size = " << vect.size() << endl;
  cout << "vect capacity = " << vect.capacity() << endl;

  cout << endl << "Add 2" << endl;
  vect.push_back(2);
  cout << "vect size = " << vect.size() << endl;
  cout << "vect capacity = " << vect.capacity() << endl;

  cout << endl << "Add 3" << endl;
  vect.push_back(3);
  cout << "vect size = " << vect.size() << endl;
  cout << "vect capacity = " << vect.capacity() << endl;

  cout << endl << "Add -1" << endl;
  vect.push_back(-1);
  cout << "vect size = " << vect.size() << endl;
  cout << "vect capacity = " << vect.capacity() << endl;

  cout << endl << "Add 1234" << endl;
  vect.push_back(1234);
  cout << "vect size = " << vect.size() << endl;
  cout << "vect capacity = " << vect.capacity() << endl;

  cout << endl << "vect contents" << endl;
  for (unsigned long i = 0; i < vect.size(); i++)
    cout << vect[i] << "  ";
  cout << endl;

  return 0;
}
