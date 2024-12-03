//Programmer: Logan Kelsch
//COSC 320 HOMEWORK 007

#include "RBTree.h"
#include "AVLTree.h"
#include <iostream>
#include <fstream>

#include <chrono>
#include <ctime>
#include <cmath>

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
    } 
    
    
    
    
    
    
    else if (selection == 4) {
        int inserts;
        int insVal;
        double bestCase;
        double worstAVL;
        double worstRB;
        double hRatio;
        
        cout<<"\nEnter Number of Nodes to Insert: ";
        cin>>inserts;
        
        for(int n = 1; n < 4; n++){
        
        cout<<"\n___________________________________________________________\n\nRandom Insertion ("<<inserts<<")";
        
        tree.kill();
        treeRB.kill();
        
        for(int i = 0; i < inserts;i++){
            insVal = rand();
            tree.insertNode(insVal);
            treeRB.insert(insVal);
        }
        
        bestCase = log2(inserts+1);
        worstAVL = 1.44 * log2(inserts+2) - 0.328;
        worstRB  = 2.00 * log2(inserts+1);
        hRatio = static_cast<double>(tree.getHeight())/treeRB.getHeight();
        
        
        cout<<"\n\t\tAVL:\t\tRB:\nBest:\t\t"<<bestCase<<"\t\t"<<bestCase<<endl;
        cout<<"Worst:\t\t"<<worstAVL<<"\t\t"<<worstRB<<endl;
        cout<<"Height:\t\t"<<tree.getHeight()<<"\t\t"<<treeRB.getHeight()<<endl;
        cout<<"HEIGHT RATIO (AVL / RB):\t"<<hRatio<<endl;
        
        cout<<"\nIn Order Insertion ("<<inserts<<")";
        
        tree.kill();
        treeRB.kill();
        
        for(int i = 0; i < inserts;i++){
            tree.insertNode(i);
            treeRB.insert(i);
        }
        
        hRatio = static_cast<double>(tree.getHeight())/treeRB.getHeight();
        
        cout<<"\n\t\tAVL:\t\tRB:\nBest:\t\t"<<bestCase<<"\t\t"<<bestCase<<endl;
        cout<<"Worst:\t\t"<<worstAVL<<"\t\t"<<worstRB<<endl;
        cout<<"Height:\t\t"<<tree.getHeight()<<"\t\t"<<treeRB.getHeight()<<endl;
        cout<<"HEIGHT RATIO (AVL / RB):\t"<<hRatio<<endl;
        
        cout<<"\nReverse Order Insertion ("<<inserts<<")";
        
        tree.kill();
        treeRB.kill();
        
        for(int i = inserts; i > 0;i--){
            tree.insertNode(i);
            treeRB.insert(i);
        }
        
        hRatio = static_cast<double>(tree.getHeight())/treeRB.getHeight();
        
        cout<<"\n\t\tAVL:\t\tRB:\nBest:\t\t"<<bestCase<<"\t\t"<<bestCase<<endl;
        cout<<"Worst:\t\t"<<worstAVL<<"\t\t"<<worstRB<<endl;
        cout<<"Height:\t\t"<<tree.getHeight()<<"\t\t"<<treeRB.getHeight()<<endl;
        cout<<"HEIGHT RATIO (AVL / RB):\t"<<hRatio<<endl;
        
        inserts*=10;
    }
        
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
    cout << "4. Run ICE 09" << endl;
    cout << "0. Quit." << endl;

    cout << "Selection: ";
    cin >> selection;
  }
  return selection;
}
