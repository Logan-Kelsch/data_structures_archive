/*
 Author: Don Spickler
 Creation Date: 1/28/2022
 Last Update: 1/28/2022
 Description: Testing program that shows some functionality of the vector and passing it
 as a parameter to functions.
 User Interface: None
 */

#include <iostream>
#include <vector>

using namespace std;

// Prototypes
template<class T, class A>
void print(vector<T, A> const &vect, bool nl = false);

template<class T, class A>
void print2(vector<T, A> const &vect, bool nl = false);

template<class T>
void print3(vector<T> const &vect, bool nl = false);

template<class T>
void printSizeCap(vector<T> const &vect);

void div(string s = "");

int main() {
	// Vector creation and population.

	div("Size, capacity, and sending as parameter. ");

	vector<int> vect;
	vector<int> vect2;

	for (int i = 0; i < 25; i++)
		vect.push_back(i + 1);

	print(vect);
	printSizeCap(vect);

	div("Pop function and shrink_to_fit.");

	vect.pop_back();
	vect.pop_back();
	printSizeCap(vect);

	print(vect);
	print2(vect);
	print3(vect);

	div("At function.");

	cout << vect.at(5) << endl;
	cout << vect[5] << endl;
	// cout << vect[50] << endl; // Error, program crash.

	vect.shrink_to_fit();
	printSizeCap(vect);

	print3(vect);

	div("Logical operators. ");

	for (int i = 0; i < 27; i++)
		vect2.push_back(i + 1);

	print3(vect);
	print3(vect2);

	cout << (vect < vect2) << endl;
	cout << (vect != vect2) << endl;
	cout << (vect == vect) << endl;
	cout << (vect != vect) << endl;

	vect[10] = 100;

	print3(vect);
	print3(vect2);

	cout << (vect < vect2) << endl;
	cout << (vect > vect2) << endl;

	div("Another size and capacity check.  Also popping from an empty list.");

	vect.clear();
	print3(vect);
	printSizeCap(vect);

	vect.pop_back();  // Nothing happens but no crash.

	cout << "End Program" << endl;

	return 0;
}

/*
 Description: Print a vector of any data type, as long as the data type can be streamed.
 Parameters: vect - Vector to be printed to the console screen.
 nl - boolean that flags if there should be a line feed after each print.
 Return: None
 */

template<class T, class A>
void print(vector<T, A> const &vect, bool nl) {
	for (T elt : vect) {
		cout << elt << " ";
		if (nl)
			cout << endl;
	}

	if (!nl)
		cout << endl;
}

/*
 Description: Print a vector of any data type, as long as the data type can be streamed.
 Parameters: vect - Vector to be printed to the console screen.
 nl - boolean that flags if there should be a line feed after each print.
 Return: None
 */

template<class T, class A>
void print2(vector<T, A> const &vect, bool nl) {
	for (unsigned long  i = 0; i < vect.size(); i++) {
		cout << vect[i] << " ";
		if (nl)
			cout << endl;
	}

	if (!nl)
		cout << endl;
}

/*
 Description: Print a vector of any data type, as long as the data type can be streamed.
 Parameters: vect - Vector to be printed to the console screen.
 nl - boolean that flags if there should be a line feed after each print.
 Return: None
 */

template<class T>
void print3(vector<T> const &vect, bool nl) {
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

template<class T>
void printSizeCap(vector<T> const &vect) {
	cout << vect.size() << "  " << vect.capacity() << endl;
}

/*
 Description: Prints a dividing line.
 Parameters: String s to print with div line.
 Return: None
 */

void div(string s) {
	cout << endl << "-------------------- " << s << endl << endl;
}
