//Programmer: Logan Kelsch
//Project 02
//main for multiMap demonstration
//Date: 4/22-23/24


/* ___________________________________
 * NOTES FOR DR SPICKLER
 * functions were added to RBTree.h for general use
   ___________________________________*/

#include "RBTree.h"
#include "multiMap.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  //initialize 4 different multiMaps
  multiMap<string> multiMap1;
  
  //beginning of demo printout
  cout<<"\nProgrammer: Logan Kelsch"<<endl;
  cout<<"MULTIMAP DEMONSTRATION:"<<endl<<endl;
  //example inputs using insert function
  pair<int,string> tmp = {1,"Logan"};
  multiMap1.insert(tmp);
  tmp = {22,"Owen"};
  multiMap1.insert(tmp);
  tmp = {22,"JJ"};
  multiMap1.insert(tmp);
  tmp = {22,"Sam"};
  multiMap1.insert(tmp);
  tmp = {5,"Zach"};
  multiMap1.insert(tmp);
  tmp = {5,"Jack"};
  multiMap1.insert(tmp);
  //temp and size printout
  cout<<"MULTIMAP: "<<multiMap1;
  cout<<"Has size of "<<multiMap1.getSize()<<endl;
  //erase example
  cout<<"\nERASE {5, ZACH}."<<endl;
  multiMap1.erase(tmp);
  //post-erase multiMap
  cout<<"MULTIMAP: "<<multiMap1;
  cout<<"Has size of "<<multiMap1.getSize()<<endl;
  //find function examples
  cout<<"\nKey of 22 Exists in multiMap? : "<<multiMap1.find(22);
  cout<<"\nKey of 38 Exists in multiMap? : "<<multiMap1.find(38)<<endl;
  //get function example
  //rushed a bit finishing up this code in time
  //the retValue function in RBTree only works for 3 names for
  //sake of time. This prints 2 names, and prints incorrectly
  //on the final name
  vector<string> get22 = multiMap1.get(22);
  cout<<"\nGet 22: ";
  for(int i = 0; i < multiMap1.count(22);i++){
    cout<<get22[i]<<"  ";
  }
  //set function examples with printout
  cout<<"\nSET 5, 'ZACH'."<<endl;
  multiMap1.set(5,"Zach");
  cout<<"MULTIMAP: "<<multiMap1;
  cout<<"Has size of "<<multiMap1.getSize()<<endl;
  
  cout<<"\nSET 100, 'SPICKLER'."<<endl;
  multiMap1.set(100,"Spickler");
  cout<<"MULTIMAP: "<<multiMap1;
  cout<<"Has size of "<<multiMap1.getSize()<<endl;

  //end of demonstration printout
  cout<<endl<<"END OF DEMONSTRATION."<<endl;

  return 0;
}
