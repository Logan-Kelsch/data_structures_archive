//Programmer: Logan Kelsch
//Project 02
//main for set demonstration
//Date: 4/22-23/24


/* ___________________________________
 * NOTES FOR DR SPICKLER
 * APPLIES TO ALL SECTIONS OF THIS PROJECT
 * functions were added to RBTree.h for general use.
 * In declaration of RB class, I have specified exactly which functions were added to the header file for the specific purposes of the different sections of this project.
 * Although, for the sake of time, I did not comment the full function. I apologize in advance, as I have no idea how you can possibly sift through this much code typed by students.
   ___________________________________*/

#include "RBTree.h"
#include "set.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  //initialize 4 different sets
  set<int> set1;
  set<int> set2;
  set<int> set3;
  set<int> set4;
    //insert demo values into set 1,2,3, leave 4 blank
  set1.insert(1);
  set1.insert(2);
  set1.insert(3);
  
  set2.insert(10);
  set2.insert(11);
  set2.insert(12);
  
  set3.insert(3);
  set3.insert(4);
  set3.insert(5);
  
  //beginning of demo printout
  cout<<"\nProgrammer: Logan Kelsch"<<endl;
  cout<<"SET DEMONSTRATION:"<<endl<<endl;
  //initial set printout
  cout<<"SET 1: "<<set1;
  cout<<"SET 2: "<<set2;
  cout<<"SET 3: "<<set3;
  cout<<"SET 4: "<<set4;
  //test isEmpty
  cout<<"\nIs set 4 empty?: "<<set4.isEmpty()<<endl;
  //test erase
  cout<<"\nRemove 12 from set 2: ";
  set2.erase(12);
  cout<<set2;
  //test getSize
  cout<<"\nSize of set 1?: "<<set1.getSize()<<endl;
  //teset Find
  cout<<"\nIs 1 in set 1?: "<<set1.find(1)<<endl;
  //test set addition
  set4 = set1+set3;
  cout<<"\nSet4 = Set1 + Set3: "<<set4;
  //test set subtraction
  set4 = set4-set3;
  cout<<"\nSet4 = Set4 - Set3: "<<set4;
  //test set intersection
  set4 = set4*set1;
  cout<<"\nSet4 = Set4 * Set1: "<<set4;
  //test many different set comparisons
  cout<<"\nSet4 < Set1 ?: "<<(set4<set1)<<endl;
  cout<<"\nSet4 > Set1 ?: "<<(set4>set1)<<endl;
  
  cout<<"\nSet2 <= Set3 ?: "<<(set2<=set3)<<endl;
  cout<<"\nSet1 >= Set4 ?: "<<(set1>=set4)<<endl;
  cout<<"\nSet1 == Set4 ?: "<<(set1==set4)<<endl;
  cout<<"\nSet2 != Set3 ?: "<<(set2!=set3)<<endl;
  //final printout of all four sets
  cout<<endl;
  cout<<"SET 1: "<<set1;
  cout<<"SET 2: "<<set2;
  cout<<"SET 3: "<<set3;
  cout<<"SET 4: "<<set4;
  //creation of array and vector for
  //toArray, toVector demonstration
  int* A;
  vector<int> V;
  int s1Size = set1.getSize();
  //filling array A and vector V
  set1.toArray(A);
  set1.toVector(V);
  //data printout
  cout<<endl<<"Set 1:"<<endl;
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
