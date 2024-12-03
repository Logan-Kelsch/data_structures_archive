//programmer: Logan Kelsch
//date: 4/3-4/4/24
//main function for homework 06

#include "AVLTree.h"
#include "BinaryTree.h"
#include <iostream>

#include <chrono>
#include <ctime>

using namespace std;
using namespace std::chrono;


//turn all BinaryTree functions to iterative

int main() {
srand(time(0));

//Create avl tree and binary tree
AVLTree<int> treeAVL;
BinaryTree<int> treeBIN;

    //val is for passing random its to both trees
    int val;
    //nUse is for the original variable counting inserts
    int nUse = 0;
    //m is for the upper bound of random numbers generated
    int m = 0;
    cout << "Input number of inserts: ";
    cin >> nUse;
    cout << "Input upper bound: ";
    cin >> m;
    //timing setups
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<< endl;
    int n = nUse;
    //for loop to run 10 iterative tests of equally incrementing n values
    for(int z = 1; z < 11; z++){
    n=nUse*z;
    //start timer
    start = high_resolution_clock::now();
    //for loop to insert AVL
    for (int i = 0; i < n; i++) {
        val = rand() % (m + 1);
        treeAVL.insertNode(val);
    }
    //stop timer
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //timing printout
    cout << "Time: [" << n << ", <" << m << "]\n\t";
    cout << "AVL: " << duration.count() / 1000000.0 << " Seconds.\n\t";
    //start DSW timing
    start = high_resolution_clock::now();
    //for loop to insert DSW
    for (int i = 0; i < n; i++) {
        val = rand() % (m + 1);
        treeBIN.insertNode(val);
    }
    //single balance call
    treeBIN.balance();
    //stop timer
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //timing printout
    cout << "DSW: " << duration.count() / 1000000.0 << " Seconds.\n\n";
    }
    
return 0;
}
