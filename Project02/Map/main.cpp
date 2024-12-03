//Programmer: Logan Kelsch
//Project 02
//main for map demonstration
//Date: 4/22-23/24


/* ___________________________________
 * NOTES FOR DR SPICKLER
 * functions were added to RBTree.h for general use
   ___________________________________*/

#include "RBTree.h"
#include "map.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  //initialize 4 different maps
  map<string> map1;
  
  //beginning of demo printout
  cout<<"\nProgrammer: Logan Kelsch"<<endl;
  cout<<"MAP DEMONSTRATION:"<<endl<<endl;
  //example inputs using insert function
  pair<int,string> tmp = {1,"Logan"};
  map1.insert(tmp);
  tmp = {22,"Owen"};
  map1.insert(tmp);
  tmp = {37,"JJ"};
  map1.insert(tmp);
  tmp = {14,"Sam"};
  map1.insert(tmp);
  tmp = {5,"Zach"};
  map1.insert(tmp);
  //temp and size printout
  cout<<"MAP: "<<map1;
  cout<<"Has size of "<<map1.getSize()<<endl;
  //erase example
  cout<<"\nERASE {5, ZACH}."<<endl;
  map1.erase(tmp);
  //post-erase map
  cout<<"MAP: "<<map1;
  cout<<"Has size of "<<map1.getSize()<<endl;
  //find function examples
  cout<<"\nKey of 22 Exists in map? : "<<map1.find(22);
  cout<<"\nKey of 38 Exists in map? : "<<map1.find(38)<<endl;
  //get function examples
  cout<<"\nGet 14: "<<map1.get(14);
  cout<<"\nGet 15: "<<map1.get(15)<<endl;
  //set function examples with printout
  cout<<"\nSET 5, 'ZACH'."<<endl;
  map1.set(5,"Zach");
  cout<<"MAP: "<<map1;
  cout<<"Has size of "<<map1.getSize()<<endl;
  
  cout<<"\nSET 100, 'SPICKLER'."<<endl;
  map1.set(100,"Spickler");
  cout<<"MAP: "<<map1;
  cout<<"Has size of "<<map1.getSize()<<endl;

  //end of demonstration printout
  cout<<endl<<"END OF DEMONSTRATION."<<endl;

  return 0;
}
