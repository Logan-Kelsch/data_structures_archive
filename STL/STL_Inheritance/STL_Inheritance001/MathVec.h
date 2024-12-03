/*
Author: Don Spickler
Creation Date: 2/10/2024
Last Update: 2/10/2024
Description: Mathematical vector class built on the STL vector class.
*/

#ifndef MATHVEC_H_
#define MATHVEC_H_

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T> class MathVec : public vector<T> {
private:
  // No data needed, all stored in the vector.
  // T should be a numeric type with the arithmetic operations defined.

public:
  MathVec();
  virtual ~MathVec();

  MathVec<T> operator+(const MathVec<T> &);
  MathVec<T> operator-(const MathVec<T> &);
  T operator*(const MathVec<T> &);

  // Normally I would not inline this but with templated friend functions this
  // is cleaner.
  friend ostream &operator<<(ostream &strm, const MathVec<T> &obj) {
    strm << "<";
    for (unsigned long i = 0; i < obj.size(); i++)
      if (i < obj.size() - 1)
        strm << obj[i] << ", ";
      else
        strm << obj[i] << ">";

    return strm;
  }
};

template <class T> MathVec<T>::MathVec() : vector<T>() {}
template <class T> MathVec<T>::~MathVec() {}

/*
Description: Vector addition, component-wise.
Parameters: A MathVec type, right
Return: MathVec holding the sum of the two math vectors.
Notes: The function assumes that the two vectors are the same size.
*/
template <class T> MathVec<T> MathVec<T>::operator+(const MathVec<T> &right) {
  MathVec<T> returnvec;

  for (unsigned long i = 0; i < (*this).size(); i++)
    returnvec.push_back((*this)[i] + right[i]);

  return returnvec;
}

/*
Description: Vector subtraction, component-wise.
Parameters: A MathVec type, right
Return: MathVec holding the sum of the two math vectors.
Notes: The function assumes that the two vectors are the same size.
*/
template <class T> MathVec<T> MathVec<T>::operator-(const MathVec<T> &right) {
  MathVec<T> returnvec;

  for (unsigned long i = 0; i < (*this).size(); i++)
    returnvec.push_back((*this)[i] - right[i]);

  return returnvec;
}

/*
Description: Vector dot product.
Parameters: A MathVec type, right
Return: Numeric type T holding the dot product of the two vectors.
Notes: The function assumes that the two vectors are the same size.
*/
template <class T> T MathVec<T>::operator*(const MathVec<T> &right) {
  T retval = 0; // Assuming that T is a numeric type.

  for (unsigned long i = 0; i < (*this).size(); i++)
    retval += (*this)[i] * right[i];

  return retval;
}

#endif /* MATHVEC_H_ */
