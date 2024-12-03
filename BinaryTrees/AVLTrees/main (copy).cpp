#include "AVLTree.h"
#include <iostream>

using namespace std;

int main() {
  srand(time(0));

  // Create the binary tree.
  AVLTree<int> tree;
  int numbernodes = 0;
  int printTrees = 1;

  cout << "Enter number of nodes to insert: ";
  cin >> numbernodes;

  //   cout << "Print Trees (Yes = 1, No = 0): ";
  //   cin >> printTrees;

  // Insert.
  if (printTrees)
    cout << "Insertion order: ";
  else
    cout << "Inserting: ";

  //*
  for (int i = 0; i < numbernodes; i++) {
    int val = rand() % 100 + 1;
    tree.insertNode(val);
    if (printTrees)
      cout << val << " ";
  }
  // */

  /*
  for (int i = 0; i < numbernodes; i++) {
      int val = i;
      tree.insertNode(val);
      if (printTrees)
          cout << val << " ";
  }
  // */

  if (printTrees) {
    //     cout << endl;
    //     cout << "\nTree:\n";
    //     tree.PrintTree();

    cout << endl;
    cout << "\nTree with height and balance values:\n";
    tree.PrintTreeHB();
  }

  cout << endl;
  if (tree.isBalanced())
    cout << "Tree is balanced." << endl;
  else
    cout << "Tree is NOT balanced." << endl;

  int nodekill = 0;
  while (nodekill >= 0) {
    cout << "Enter node to remove: ";
    cin >> nodekill;

    tree.remove(nodekill);

    if (printTrees) {
      cout << endl;
      cout << "\nTree with height and balance values:\n";
      tree.PrintTreeHB();

      cout << endl;
      if (tree.isBalanced())
        cout << "Tree is balanced." << endl;
      else
        cout << "Tree is NOT balanced." << endl;
    }
  }

  //   cout << endl;
  //   cout << "Enter number of nodes to remove: ";
  //   cin >> numbernodes;
  //
  //   if (printTrees)
  //     cout << "Remove order: ";
  //   else
  //     cout << "Removing: ";
  //
  //   for (int i = 0; i < numbernodes; i++) {
  //     int val = rand() % 100 + 1;
  //     tree.remove(val);
  //     if (printTrees)
  //       cout << val << " ";
  //   }
  //
  //   if (printTrees) {
  //     cout << endl;
  //     cout << "\nTree with height and balance values:\n";
  //     tree.PrintTreeHB();
  //   }
  //
  //   cout << endl;
  //   if (tree.isBalanced())
  //     cout << "Tree is balanced." << endl;
  //   else
  //     cout << "Tree is NOT balanced." << endl;
  //
  //   AVLTree<int> tree2;
  //
  //   for (int i = 0; i < 1000; i++) {
  //     tree2.kill();
  //     for (int i = 0; i < numbernodes; i++) {
  //       int val = rand() % 100 + 1;
  //       tree2.insertNode(val);
  //     }
  //
  //     if (!tree2.isBalanced())
  //       cout << "Tree is NOT balanced +++++++++++++++++++++++." << endl;
  //
  //     for (int i = 0; i < numbernodes; i++) {
  //       int val = rand() % 100 + 1;
  //       tree2.remove(val);
  //     }
  //     if (!tree2.isBalanced()){
  //       cout << "Delete Tree is NOT balanced --------------------- ." <<
  //       endl;
  //     tree2.PrintTreeHB();
  //     }
  // //     cout << "\n ";
  //   }

  return 0;
}
