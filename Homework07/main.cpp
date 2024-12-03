//Programmer: Logan Kelsch
//COSC 320 HOMEWORK 007

#include "RBTree.h"
#include "AVLTree.h"
#include <iostream>
#include <fstream>

#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;

int getOption();

//USER OPTION 4 IS THE FUNCTION TO TIME THE OPERATIONS

int main() {
  srand(time(0));

  // Create the binary tree.
  AVLTree<int> tree;
  RBTree<int> treeRB;
  int selection = 1;

  while (selection != 0) {
    selection = getOption();
    int initNodes = 0;
    //upper bound variable
    int ub = 0;
    //initialize timing variables
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    //concept for int/del cyc timing,
    //make temp trees that will duplicate
    //first tree data

    if (selection == 1) {
      int inserts = 0;
      int insVal;
      cout << "Number of Nodes to Insert: ";
      cin >> inserts;
      initNodes+=inserts;
      cout << "Input upper bound: ";
      cin >> ub;
      for (int i = inserts; i > 0; i--) {
        insVal = rand() % ub + 1;
        tree.insertNode(insVal);
        treeRB.insert(insVal);
      }
    } else if (selection == 2) {
      int cycles = 0;
      int insVal;
      int delVal = 0;
      cout << "Number of Ins/Del Cycles: ";
      cin >> cycles;
      cout << "Input upper bound: ";
      cin >> ub;
      //cycleNodes+=cycles;
      for (int i = 0; i < cycles; i++){
        insVal = rand() % ub + 1;
        tree.insertNode(insVal);
        treeRB.insert(insVal);
        while(!tree.searchNode(delVal)){
            delVal = rand() % ub + 1;
        }
        tree.remove(delVal);
        treeRB.remove(delVal);
      }
    } else if (selection == 3) {
        cout<< endl << "IPL AVG:\n\t(AVL): " <<tree.avgIPL()<< "\n\t (RB): "<<treeRB.avgIPL()<<endl;
    } else if (selection == 4) {
        //test timing of functions
        
        //open file to output data to
        ofstream out;
        out.open("out.txt");
        //run 10 timing tests with equal incrementing values
        for(int n = 1; n < 11; n++){
            //reset trees every test
            tree.kill();
            treeRB.kill();
            //factor is used for ease of incrementing
            int factor =    50000;
            int inserts =   n*factor;
            int cycles =    n*factor;
            ub =            n*factor;
            //clarify to user data that is being computed
            cout<< "\nins: "<<inserts<<" - cyc: "<<cycles<<" - ub: "<<ub;
            //out<< "\nins: "<<inserts<<" - cyc: "<<cycles<<" - ub: "<<ub;
            //delete value and insert value, used in future inserts and deletes
            int delVal;
            int insVal;
            //start time
            start = high_resolution_clock::now();
            //insert random value loop in AVL tree
            for (int i = inserts; i > 0; i--) {
                insVal = rand() % ub + 1;
                tree.insertNode(insVal);
            }
            //finish timing and output results to console and file
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "\n(AVL-ins): avgIPL - " << tree.avgIPL() << " , Time - " << duration.count()/1000000.0;
            out << "\n" << tree.avgIPL() << "\t" << duration.count()/1000000.0;
            //start RB timing 
            start = high_resolution_clock::now();
            //insert random value loop in RB tree
            for (int i = inserts; i > 0; i--) {
                insVal = rand() % ub + 1;
                treeRB.insert(insVal);
            }
            //finish timing and output results to console and file
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "\n(RB-ins): avgIPL - " << treeRB.avgIPL() << " , Time - " << duration.count()/1000000.0;
            out << "\n" << treeRB.avgIPL() << "\t" << duration.count()/1000000.0;
            //start AVL ins/del cycle
            start = high_resolution_clock::now();
            //for loop for inserting random values and them deleting random values
            for (int i = 0; i < cycles; i++){
                insVal = rand() % ub + 1;
                tree.insertNode(insVal);
                while(!tree.searchNode(delVal)){
                    delVal = rand() % ub + 1;
                }
                tree.remove(delVal);
            }
            //finish timing and output results to console and file
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "\n(AVL-cyc): avgIPL - " << treeRB.avgIPL() << " , Time - " << duration.count()/1000000.0;
            out << "\n" << tree.avgIPL() << "\t" << duration.count()/1000000.0;
            //start RB ins/del cycles
            start = high_resolution_clock::now();
            //for loop for inserting random values and then deleting random values
            for (int i = 0; i < cycles; i++){
                insVal = rand() % ub + 1;
                treeRB.insert(insVal);
                while(!treeRB.find(delVal)){
                    delVal = rand() % ub + 1;
                }
                treeRB.remove(delVal);
            }
            //finish timing and output results to console and file
            stop = high_resolution_clock::now();
            duration = duration_cast<microseconds>(stop - start);
            cout << "\n(RB-cyc): avgIPL - " << treeRB.avgIPL() << " , Time - " << duration.count()/1000000.0;
            out << "\n" << treeRB.avgIPL() << "\t" << duration.count()/1000000.0;
            cout<<endl;
        }
        //close file
        out.close();
    }
  }

  return 0;
}

int getOption() {
  int selection = -1;

  while (selection < 0 || selection > 8) {
    cout << endl;
    cout << "Options:" << endl;
    cout << "1. Insert random values." << endl;
    cout << "2. Run Insertion/Deletion Timing Cycle" << endl;
    cout << "3. Find IPLs" << endl;
    cout << "4. Run Timing" << endl;
    cout << "0. Quit." << endl;

    cout << "Selection: ";
    cin >> selection;
  }
  return selection;
}
