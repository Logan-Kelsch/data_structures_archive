//Implementation file for the IntBinaryTree class
//MODIFIED BY: Logan Kelsch
//COSC320 3/8/24
//Functions implemented for activity
#include <iostream>
#include "IntBinaryTree.h"
using namespace std;

//4 functions were added by Logan Kelsch for ICE02
//numNones - countNodes
//numLeaves - countLeaves
//height
//printHeightPaths



//height():calls recursive heightCount()
int IntBinaryTree::height(){
    return heightCount(root, 1);
}

//heightCount(): returns height of tree
int IntBinaryTree::heightCount(TreeNode *&nodePtr, int count){
    //leaf and single child condition
    if(nodePtr->left==NULL||nodePtr->right==NULL){
        ++count;
        if(nodePtr->left!=NULL)
            return heightCount(nodePtr->left,count);
        if(nodePtr->right!=NULL)
            return heightCount(nodePtr->right,count);
        return count;
    } else { // two child condition, grabs taller child
        return(heightCount(nodePtr->left,count)>heightCount(nodePtr->right,count))?heightCount(nodePtr->left,count):heightCount(nodePtr->right,count);
    }
}

//countNodes():calls recursive numNodes()
int IntBinaryTree::countNodes(){
    return numNodes(root, 0);
}
//numNones():returns total number of nodes in the entire tree
int IntBinaryTree::numNodes(TreeNode *&nodePtr, int count){
    if(nodePtr->left!=NULL){
        count=numNodes(nodePtr->left,count);
    }
    if(nodePtr->right!=NULL){
        count=numNodes(nodePtr->right,count);
    }
    return ++count;
}

//printHeight():calls recursive heightCount()
void IntBinaryTree::printHeight(){
    cout<<"\nLongest Path:\n\t";
     PrintHeightPaths(root);
     cout<<endl;
}

//PrintHeightPaths(): returns height of tree
void IntBinaryTree::PrintHeightPaths(TreeNode *&nodePtr){
    //leaf and single child condition
    cout<<nodePtr->value<<" ";
    if(nodePtr->left==NULL||nodePtr->right==NULL){
        if(nodePtr->left!=NULL)
            return PrintHeightPaths(nodePtr->left);
        if(nodePtr->right!=NULL)
            return PrintHeightPaths(nodePtr->right);
    } else { // two child condition, grabs taller child
        if(heightCount(nodePtr->left,0)>heightCount(nodePtr->right,0))
            PrintHeightPaths(nodePtr->left);
        else
            PrintHeightPaths(nodePtr->right);
    }
}

//countLeaves():calls recursive numLeaves()
int IntBinaryTree::countLeaves(){
    return numLeaves(root,0);
}

//numLeaves():returns recursive total of leaves in the entire tree
int IntBinaryTree::numLeaves(TreeNode *&nodePtr, int count){
    if(nodePtr->left==NULL&&nodePtr->right==NULL)
        return ++count;
    else {
        if(nodePtr->left!=NULL){
            count=numLeaves(nodePtr->left,count);
        }
        if(nodePtr->right!=NULL){
            count=numLeaves(nodePtr->right,count);
        }
    }
    return count;
}



//numLeaves():returns total number of leaf nodes in the entire tree
//height():returns height of tree
//PrintHeightPaths():

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
	if (nodePtr == nullptr)
		nodePtr = newNode;                  // Insert the node.
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);     // Search the left branch
	else
		insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void IntBinaryTree::insertNode(int num) {
	TreeNode *newNode = nullptr;	// Pointer to a new node.

	// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void IntBinaryTree::destroySubTree(TreeNode *nodePtr) {
	if (nodePtr) {
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************

bool IntBinaryTree::searchNode(int num) {
	TreeNode *nodePtr = root;

	while (nodePtr) {
		if (nodePtr->value == num)
			return true;
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

void IntBinaryTree::remove(int num) {
	deleteNode(num, root);
}

//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr) {
	if (num < nodePtr->value)
		deleteNode(num, nodePtr->left);
	else if (num > nodePtr->value)
		deleteNode(num, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr) {
	// Define a temporary pointer to use in reattaching
	// the left subtree.
	TreeNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;   // Reattach the left child
		delete tempNodePtr;
	} else if (nodePtr->left == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;  // Reattach the right child
		delete tempNodePtr;
	}
	// If the node has two children.
	else {
		// Move one node the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const {
	if (nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

//****************************************************************
// Simple helper function to do the indentations for the tree
// printing algorithm.
//****************************************************************

void IntBinaryTree::IndentBlock(int num) {
	for (int i = 0; i < num; i++)
		cout << " ";
}

//****************************************************************
// This function recursively prints the tree contents to the
// console using a reverse inorder traversal with indenting.
//****************************************************************

void IntBinaryTree::PrintTree(TreeNode *t, int Indent, int Level) {
	if (t != NULL) {
		PrintTree(t->right, Indent, Level + 1);
		IndentBlock(Indent * Level);
		cout << t->value << "\n";
		PrintTree(t->left, Indent, Level + 1);
	}
}

//****************************************************************
// This function initiates the recursive printing function to
// print the contents of the tree in tree form sideways with the
// root at the far left.
//****************************************************************

void IntBinaryTree::PrintTree(int Indent, int Level) {
	if (root != NULL)
		PrintTree(root, Indent, Level);
}

