#ifndef RBTREE_H_
#define RBTREE_H_

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

enum color_t {
	RED, BLACK
// Red = 0, Black = 1
};

template<class T>
class RBTreeNode {
public:
	pair<int,T> value;
	color_t color;
	RBTreeNode *left;
	RBTreeNode *right;
	RBTreeNode *parent;

	RBTreeNode() {
		left = nullptr;
		right = nullptr;
		parent = nullptr;
		color = RED;
	}

	RBTreeNode(pair<int,T> val, color_t col, RBTreeNode *l, RBTreeNode *r,
			RBTreeNode *p) {
		value = val;
		left = l;
		right = r;
		parent = p;
		color = col;
	}
};

template<class T>
class RBTree {
protected:
	RBTreeNode<T> *root;
	RBTreeNode<T> *NIL;
	void IndentBlock(int num);
	void PrintTree(RBTreeNode<T>*, int, int);

	void LeftRotation(RBTreeNode<T>*);
	void RightRotation(RBTreeNode<T>*);
	void insertFix(RBTreeNode<T>*);

	void transplant(RBTreeNode<T>*, RBTreeNode<T>*);
	void deleteFix(RBTreeNode<T>*);
	RBTreeNode<T>* getMinNode(RBTreeNode<T>*);

	void destroySubTree(RBTreeNode<T>*)const;
    int leafCount(RBTreeNode<T> *);
    int totalIPLRec(RBTreeNode<T> *, int);
    //________________________________________
    //PROJECT 2 SPECIFIC PRIVATE FUNCTIONS
    int size(RBTreeNode<T> *)const;
    void toVectorREC(RBTreeNode<T> *,vector<pair<int,T>>&)const;
    void toArrayREC(RBTreeNode<T> *,pair<int,T>*&,int&)const;
    //________________________________________
    
public:
	RBTree();
	virtual ~RBTree();
    //_________________________________________
    //PROJECT 2 SPECIFIC PUBLIC FUNCTIONS
    bool isEmpty()const;
    int getSize()const;
    vector<pair<int,T>> toVector(vector<pair<int,T>>) const;
    pair<int,T>* toArray(pair<int,T>*&) const;
    T retValue(int);
    //_________________________________________
    
	void insert(pair<int,T>);
	void remove(pair<int,T>);
    
    int height(RBTreeNode<T> *);
    int getHeight();
    
    double avgIPL();

	bool find(const int &item);
	RBTreeNode<T>* findNode(const int&);

	void PrintTree(int Indent = 4, int Level = 0);
    
    void kill(){
    destroySubTree(root);
    root = NIL;
  }
};

template<class T>
RBTree<T>::RBTree() {
    pair<int,T> val;
    val.first = -1;
    val.second = "OUT_OF_RANGE";
	NIL = new RBTreeNode<T>(val, BLACK, nullptr, nullptr, nullptr);
	root = NIL;
}

template<class T>
RBTree<T>::~RBTree() {
	destroySubTree(root);
	delete NIL;
}
template<class T>
T RBTree<T>::retValue(int A){
    return findNode(A)->value.second;
}
template<class T>
pair<int,T>* RBTree<T>::toArray(pair<int,T>*& A) const{
    int count = 0;
    toArrayREC(root,A,count);
    return A;
}
template<class T>
void RBTree<T>::toArrayREC(RBTreeNode<T> *tmp, pair<int,T>*& A, int &count) const{
    if (tmp != NIL) {
		toArrayREC(tmp->left,A,count);
		A[count++]=tmp->value;
        toArrayREC(tmp->right,A,count);
	}
}
template<class T>
vector<pair<int,T>> RBTree<T>::toVector(vector<pair<int,T>> vect) const{
    toVectorREC(root,vect);
    return vect;
}
template<class T>
void RBTree<T>::toVectorREC(RBTreeNode<T> *tmp, vector<pair<int,T>>& vect) const{
    if (tmp != NIL) {
		toVectorREC(tmp->left,vect);
		vect.push_back(tmp->value);
        toVectorREC(tmp->right,vect);
	}
}
//size function to call REC "size" for Project 2
template<class T>
int RBTree<T>::getSize()const{
    if(isEmpty())
        return 0;
    return size(root);
}
//REC function to return size of subtree for Project 2
template<class T>
int RBTree<T>::size(RBTreeNode<T> *tmp)const{
    return (tmp==NIL)?0:size(tmp->left)+size(tmp->right)+1;
        
}

template<class T>
bool RBTree<T>::isEmpty()const{
    return(root==NIL)?true:false;
}

template <class T> int RBTree<T>::height(RBTreeNode<T> * nodePtr){
    if(nodePtr==NIL)
        return 0;
    return max(height(nodePtr->left),height(nodePtr->right))+1;
}

template <class T> int RBTree<T>::getHeight(){
    return height(root);
}

template <class T> int RBTree<T>::leafCount(RBTreeNode<T> *tmp){
    if(tmp){
        if(!tmp->right&&!tmp->left)
            return 1;
        else 
            return leafCount(tmp->left)+leafCount(tmp->right);
    }
    return 0;
}

template <class T> double RBTree<T>::avgIPL(){
    return static_cast<double>(totalIPLRec(root,0))/leafCount(root);
}

template <class T> int RBTree<T>::totalIPLRec(RBTreeNode<T> *nodePtr, int height){
    if (nodePtr) {
        height++;
        if(!nodePtr->left&&!nodePtr->right)
            return height;
        else
            return totalIPLRec(nodePtr->left,height) + totalIPLRec(nodePtr->right,height);
    }
  return 0;
}

/*
 * Recursively frees the memory of the subtree pointed to by nodePtr.
 */
template<class T>
void RBTree<T>::destroySubTree(RBTreeNode<T> *nodePtr) const{
	if (nodePtr != NIL) {
		if (nodePtr->left != NIL)
			destroySubTree(nodePtr->left);
		if (nodePtr->right != NIL)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

/*
 * Inserts a new node into the RB-Tree as with a standard BST but then calls the
 * insertFix function to adjust the tree back to an RB tree.
 */
template<class T>
void RBTree<T>::insert(pair<int,T> val){
	RBTreeNode<T> *newnode = new RBTreeNode<T>(val, RED, NIL, NIL, NIL);
	RBTreeNode<T> *y = NIL;
	RBTreeNode<T> *x = root;

	while (x != NIL) {
		y = x;
		if (val.first < x->value.first)
			x = x->left;
		else
			x = x->right;
	}
	newnode->parent = y;
	if (y == NIL)
		root = newnode;
	else if (newnode->value.first < y->value.first)
		y->left = newnode;
	else
		y->right = newnode;

	//  Adjust the RB tree to retain the properties.
	insertFix(newnode);
}

/*
 * Adjusts the tree back to an RB tree after insertion of a new node.
 */
template<class T>
void RBTree<T>::insertFix(RBTreeNode<T> *z) {
	RBTreeNode<T> *y = NIL;

	while (z->parent->color == RED) {
		if (z->parent == z->parent->parent->left) {
			y = z->parent->parent->right;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			} else {
				if (z == z->parent->right) {
					z = z->parent;
					LeftRotation(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				RightRotation(z->parent->parent);
			}
		} else {
			y = z->parent->parent->left;
			if (y->color == RED) {
				z->parent->color = BLACK;
				y->color = BLACK;
				z->parent->parent->color = RED;
				z = z->parent->parent;
			} else {
				if (z == z->parent->left) {
					z = z->parent;
					RightRotation(z);
				}
				z->parent->color = BLACK;
				z->parent->parent->color = RED;
				LeftRotation(z->parent->parent);
			}
		}
	}
	root->color = BLACK;
}

/*
 * This is a helper function to the node deletion process.
 */
template<class T>
void RBTree<T>::transplant(RBTreeNode<T> *u, RBTreeNode<T> *v) {
	if (u->parent == NIL)
		root = v;
	else if (u == u->parent->left)
		u->parent->left = v;
	else
		u->parent->right = v;
	v->parent = u->parent;
}

/*
 * Finds the smallest node in the subtree pointed to by x.  As usual
 * we traverse down the left branch as far as possible.  The node y
 * tracks x's parent so that when x == NIL, y is the minimum valued
 * node.
 */
template<class T>
RBTreeNode<T>* RBTree<T>::getMinNode(RBTreeNode<T> *x) {
	if (x == NIL)
		return NIL;

	RBTreeNode<T> *y = NIL;
	while (x != NIL) {
		y = x;
		x = x->left;
	}
	return y;
}

/*
 * Finds and deletes the node whose value is val.  Calls the deleteFix function
 * to readjust the tree back to RB format.
 */
template<class T>
void RBTree<T>::remove(pair<int,T> val) {
	RBTreeNode<T> *z = findNode(val.first);
	if (z == NIL)
		return;

	RBTreeNode<T> *y = z;
	RBTreeNode<T> *x = NIL;
	color_t yorigcol = y->color;

	if (z->left == NIL) {
		x = z->right;
		transplant(z, z->right);
	} else if (z->right == NIL) {
		x = z->left;
		transplant(z, z->left);
	} else {
		y = getMinNode(z->right);
		yorigcol = y->color;
		x = y->right;
		if (y->parent == z)
			x->parent = y;
		else {
			transplant(y, y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		transplant(z, y);
		y->left = z->left;
		y->left->parent = y;
		y->color = z->color;
	}
	delete z;
	if (yorigcol == BLACK)
		deleteFix(x);
}

/*
 * Readjusts the RB tree to fix any violated properties after the deletion of a
 * node.
 */
template<class T>
void RBTree<T>::deleteFix(RBTreeNode<T> *x) {
	RBTreeNode<T> *w = NIL;

	while (x != root && x->color == BLACK) {
		if (x == x->parent->left) {
			w = x->parent->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				LeftRotation(x->parent);
				w = x->parent->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			} else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					RightRotation(w);
					w = x->parent->right;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->right->color = BLACK;
				LeftRotation(x->parent);
				x = root;
			}
		} else {
			w = x->parent->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->parent->color = RED;
				RightRotation(x->parent);
				w = x->parent->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->parent;
			} else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					LeftRotation(w);
					w = x->parent->left;
				}
				w->color = x->parent->color;
				x->parent->color = BLACK;
				w->left->color = BLACK;
				RightRotation(x->parent);
				x = root;
			}
		}
	}
	x->color = BLACK;
}

/*
 * This returns true if the item is in the RB-tree and false otherwise.
 * It simply calls the node based recursive version and checks the result
 * against the NIL object.
 */
template<class T>
bool RBTree<T>::find(const int &item) {
	return findNode(item) != NIL;
}

/*
 Does a right rotation at the input node.
 The function also updates the height values for the nodes.

 Parameters
 x --- pointer to the node to rotate right around.
 */

template<class T>
void RBTree<T>::RightRotation(RBTreeNode<T> *x) {
	RBTreeNode<T> *y = x->left;
	x->left = y->right;

	if (y->right != NIL)
		y->right->parent = x;

	y->parent = x->parent;

	if (x->parent == NIL)
		root = y;
	else if (x == x->parent->right)
		x->parent->right = y;
	else
		x->parent->left = y;

	y->right = x;
	x->parent = y;
}

/*
 Does a left rotation at the input node.
 The function also updates the height values for the nodes.

 Parameters
 nodePtr --- pointer to the node to rotate right around.
 */

template<class T>
void RBTree<T>::LeftRotation(RBTreeNode<T> *x) {
	RBTreeNode<T> *y = x->right;
	x->right = y->left;

	if (y->left != NIL)
		y->left->parent = x;

	y->parent = x->parent;

	if (x->parent == NIL)
		root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;

	y->left = x;
	x->parent = y;
}

/*
 * Recursive find function that finds the first node containing the value item.
 */
template<class T>
RBTreeNode<T>* RBTree<T>::findNode(const int &item) {
	RBTreeNode<T> *nodePtr = root;

	while (nodePtr != NIL) {
		if (nodePtr->value.first == item)
			return nodePtr;
		else if (item < nodePtr->value.first)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return NIL;
}

//****************************************************************
// Simple helper function to do the indentations for the tree
// printing algorithm.
//****************************************************************
template<class T>
void RBTree<T>::IndentBlock(int num) {
	for (int i = 0; i < num; i++)
		cout << " ";
}

//****************************************************************
// This function recursively prints the tree contents to the
// console using a reverse inorder traversal with indenting.
// This includes the height and balance factor of each node.
//****************************************************************
/*
template<class T>
void RBTree<T>::PrintTree(RBTreeNode<T> *t, int Indent, int Level) {
	if (t != NIL) {
		PrintTree(t->right, Indent, Level + 1);

		string RBstr;
		if (t->color == RED)
			RBstr = "R";
		else
			RBstr = "B";

		IndentBlock(Indent * Level);
		cout << t->value << " (" << RBstr << ")" << endl;

		PrintTree(t->left, Indent, Level + 1);
	}
}
*/
//****************************************************************
// This function initiates the recursive printing function to
// print the contents of the tree in tree form sideways with the
// root at the far left. This includes the height and balance
// factor of each node.
//****************************************************************
/*
template<class T>
void RBTree<T>::PrintTree(int Indent, int Level) {
	if (root)
		PrintTree(root, Indent, Level);
}
*/
#endif /* RBTREE_H_ */
