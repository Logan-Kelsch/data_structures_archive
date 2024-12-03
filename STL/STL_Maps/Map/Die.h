/*
Author: Don Spickler
Creation Date: 2/10/2024
Last Update: 2/10/2024
Description: Simple die class simulating an n-sided die.
*/

#ifndef DIE_H
#define DIE_H

#include <iostream>
using namespace std;

class Die {
private:
  int sides;
  int value;

public:
  Die(int numSides = 6);
  void roll();
  int getSides() const;
  int getValue() const;

  bool operator==(const Die &);
  bool operator!=(const Die &);
  bool operator<(const Die &) const;

  friend ostream &operator<<(ostream &, const Die &);
};
#endif
