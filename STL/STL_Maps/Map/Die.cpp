/*
Author: Don Spickler
Creation Date: 2/10/2024
Last Update: 2/10/2024
*/

#include "Die.h"

using namespace std;

/*
Description: Constructor
Parameters: numSides, the number of sides to the die.
Return: None
Notes: Does a die roll on creation.
*/
Die::Die(int numSides) {
  sides = numSides;
  roll();
}

/*
Description: Rolls the die.
Parameters: None
Return: None
*/
void Die::roll() { value = (rand() % sides) + 1; }

/*
Description: Returns the number of sides on the die.
Parameters: None
Return: Number of sides to the die.
*/
int Die::getSides() const { return sides; }

/*
Description: Returns the current die roll value.
Parameters: None
Return: The current die roll value.
*/
int Die::getValue() const { return value; }

/*
Description: Overloaded == operator.
Parameters: die d2.
Return: True if the values of the dies are equal.
*/
bool Die::operator==(const Die &d2) { return value == d2.value; }

/*
Description: Overloaded != operator.
Parameters: die d2.
Return: True if the values of the dies are not equal.
*/
bool Die::operator!=(const Die &d2) { return value != d2.value; }

/*
Description: Overloaded < operator.
Parameters: die d2.
Return: True if the value of calling die is less than the parameter die.
*/
bool Die::operator<(const Die &d2) const { return value < d2.value; }

/*
Description: Overloaded << operator.
Parameters: die d2.
Return: Stream out object.
*/
ostream &operator<<(ostream &strm, const Die &d2) { return strm << d2.value; }
