/*
Author: Don Spickler
Creation Date: 1/27/2022
Last Update: 1/27/2022
Description: Splits a string at delimiter character.
User Interface: None
Notes: None
*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void div() { cout << "\n---------------------------\n\n"; }

template <class T> void pt(T item) { cout << item << " "; }
template <class T> void ptn(T item) { cout << item << endl; }

vector<string> split(string str, char delimiter) {
  vector<string> tokens;
  string tokenstr;
  stringstream strstream(str);

  while (getline(strstream, tokenstr, delimiter))
    tokens.push_back(tokenstr);

  return tokens;
}

int main() {
  string str;
  string delimiterstr;
  char delimiter;
  cout << "Input a string: ";
  getline(cin, str);

  cout << "Input a delimiter: ";
  getline(cin, delimiterstr);

  delimiter = delimiterstr[0];
  vector<string> tokens = split(str, delimiter);
  for_each(tokens.begin(), tokens.end(), ptn<string>);

  return 0;
}
