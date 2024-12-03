#include "AVLTree.h"
#include <iostream>

using namespace std;

int getOption();

int main() {
  srand(time(0));

  // Create the binary tree.
  AVLTree<int> tree;
  int selection = 1;

  while (selection != 0) {
    selection = getOption();
    int val;

    if (selection == 1) {
      cout << "Input an integer to insert: ";
      cin >> val;
      tree.insert(val);
    } else if (selection == 2) {
      int num = 0;
      int lb = 0;
      int ub = 0;
      cout << "Input number to insert: ";
      cin >> num;
      cout << "Input lower bound: ";
      cin >> lb;
      cout << "Input upper bound: ";
      cin >> ub;
      for (int i = 0; i < num; i++) {
        val = rand() % (ub - lb + 1) + lb;
        tree.insert(val);
      }
    } else if (selection == 3) {
      cout << "Input an integer to remove: ";
      cin >> val;
      tree.remove(val);
    } else if (selection == 4) {
      int num = 0;
      int lb = 0;
      int ub = 0;
      cout << "Input number to remove: ";
      cin >> num;
      cout << "Input lower bound: ";
      cin >> lb;
      cout << "Input upper bound: ";
      cin >> ub;
      // Note: Not testing val to be in the tree, so some removes
      // will not remove an item.
      for (int i = 0; i < num; i++) {
        val = rand() % (ub - lb + 1) + lb;
        tree.remove(val);
      }
    } else if (selection == 5) {
      cout << endl;
      tree.PrintTreeHB();
      cout << endl;
    } else if (selection == 6) {
      if (tree.isBST())
        cout << "Tree is a BST." << endl;
      else
        cout << "Tree is NOT a BST." << endl;
    } else if (selection == 7) {
      if (tree.isBalanced())
        cout << "Tree is balanced." << endl;
      else
        cout << "Tree is NOT balanced." << endl;
    } else if (selection == 8) {
      cout << "Input an integer to find: ";
      cin >> val;

      if (tree.search(val))
        cout << "Found" << endl;
      else
        cout << "Not found" << endl;
    } else if (selection == 9) {
      tree.PreOrder([](int &a) { cout << a << " "; });
      cout << endl;
    } else if (selection == 10) {
      tree.InOrder([](int &a) { cout << a << " "; });
      cout << endl;
    } else if (selection == 11) {
      tree.PostOrder([](int &a) { cout << a << " "; });
      cout << endl;
    }
  }

  return 0;
}

int getOption() {
  int selection = -1;

  while (selection < 0 || selection > 11) {
    cout << endl;
    cout << "Options" << endl;
    cout << "1. Insert one value." << endl;
    cout << "2. Insert random values." << endl;
    cout << "3. Remove one value." << endl;
    cout << "4. Remove random values." << endl;
    cout << "5. Print tree." << endl;
    cout << "6. Test BST." << endl;
    cout << "7. Test balanced." << endl;
    cout << "8. Find value." << endl;
    cout << "9. Print preorder." << endl;
    cout << "10. Print inorder." << endl;
    cout << "11. Print postorder." << endl;
    cout << "0. Quit." << endl;

    cout << "Selection: ";
    cin >> selection;
  }
  return selection;
}
