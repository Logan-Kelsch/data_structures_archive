//Programmer: Logan Kelsch
//Project 02
//main for multiSet demonstration
//Date: 4/22-24/24


/* ___________________________________
 * NOTES FOR DR SPICKLER
 * functions were added to RBTree.h for general use
   ___________________________________*/

#include "RBTree.h"
#include "multiSet.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  //initialize 4 different multiSets
  multiSet<int> multiSet1;
  multiSet<int> multiSet2;
  multiSet<int> multiSet3;
  multiSet<int> multiSet4;
  //insert demo values into multiSet 1,2,3, leave 4 blank
  multiSet1.insert(1);
  multiSet1.insert(2);
  multiSet1.insert(3);
  multiSet1.insert(3);
  
  multiSet2.insert(10);
  multiSet2.insert(11);
  multiSet2.insert(12);
  
  multiSet3.insert(3);
  multiSet3.insert(4);
  multiSet3.insert(5);
  
  //beginning of demo printout
  cout<<"\nProgrammer: Logan Kelsch"<<endl;
  cout<<"MULTISET DEMONSTRATION:"<<endl<<endl;
  //initial multiSet printout
  cout<<"multiSet 1: "<<multiSet1;
  cout<<"multiSet 2: "<<multiSet2;
  cout<<"multiSet 3: "<<multiSet3;
  cout<<"multiSet 4: "<<multiSet4;
  //test isEmpty
  cout<<"\nIs multiSet 4 empty?: "<<multiSet4.isEmpty()<<endl;
  //test count
  cout<<"\nHow many 3's in multiSet 1?: ";
  cout<<multiSet1.count(3)<<endl;
  //test erase
  cout<<"\nRemove 12 from multiSet 2: ";
  multiSet2.erase(12);
  cout<<multiSet2;
  //test getSize
  cout<<"\nSize of multiSet 1?: "<<multiSet1.getSize()<<endl;
  //temultiSet Find
  cout<<"\nIs 1 in multiSet 1?: "<<multiSet1.find(1)<<endl;
  //test multiSet addition
  multiSet4 = multiSet1+multiSet3;
  cout<<"\nmultiSet4 = multiSet1 + multiSet3:\n"<<multiSet4;
  //test multiSet subtraction
  multiSet4 = multiSet4-multiSet3;
  cout<<"\nmultiSet4 = multiSet4 - multiSet3:\n"<<multiSet4;
  //test multiSet intersection
  multiSet4 = multiSet4*multiSet1;
  cout<<"\nmultiSet4 = multiSet4 * multiSet1:\n"<<multiSet4;
  //test many different multiSet comparisons
  cout<<"\nmultiSet4 < multiSet1 ?: "<<(multiSet4<multiSet1)<<endl;
  cout<<"\nmultiSet4 > multiSet1 ?: "<<(multiSet4>multiSet1)<<endl;
  
  cout<<"\nmultiSet2 <= multiSet3 ?: "<<(multiSet2<=multiSet3)<<endl;
  cout<<"\nmultiSet1 >= multiSet4 ?: "<<(multiSet1>=multiSet4)<<endl;
  cout<<"\nmultiSet1 == multiSet4 ?: "<<(multiSet1==multiSet4)<<endl;
  cout<<"\nmultiSet2 != multiSet3 ?: "<<(multiSet2!=multiSet3)<<endl;
  //final printout of all four multiSets
  cout<<endl;
  cout<<"multiSet 1: "<<multiSet1;
  cout<<"multiSet 2: "<<multiSet2;
  cout<<"multiSet 3: "<<multiSet3;
  cout<<"multiSet 4: "<<multiSet4;
  //creation of array and vector for
  //toArray, toVector demonstration
  int* A;
  vector<int> V;
  int s1Size = multiSet1.getSize();
  //filling array A and vector V
  multiSet1.toArray(A);
  multiSet1.toVector(V);
  //data printout
  cout<<endl<<"multiSet 1:"<<endl;
  //printout of array data
  cout<<"TO ARRAY:\t";
  for(int i = 0;i<s1Size;i++)
    cout<< A[i]<<" ";
  cout<<endl;
  //printout of vector data
  cout<<"TO VECTOR:\t";
  for(int i = 0;i<s1Size;i++)
    cout<< V[i]<<" ";
  cout<<endl;
  //end of demonstration printout
  cout<<endl<<"END OF DEMONSTRATION."<<endl;

  return 0;
}
