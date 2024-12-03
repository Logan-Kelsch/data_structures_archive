//Programmer: Logan Kelsch
//Date: 4/22-23/24
//Project 2
//header+function file for set 

#ifndef SET_H_
#define SET_H_

#include "RBTree.h"
#include <iostream>
#include <vector>

using namespace std;
//TEMPLATED SET CLASS
//all functions are written outside of braces, 
//except for << friend operator overloader
template<class T>
class set {
private:
    //only private member, red-black tree
    RBTree<T> tree;
public:
    //constructor,copy constructor,destructor
    set();
    set(const set<T>&);
    ~set();
    //all other public call functions
    void insert(T);
    bool isEmpty()const;
    int getSize()const;
    void clear();
    void erase(T);
    bool find(T);
    void toVector(vector<T>&)const;
    void toArray(T*&)const;
    //overloaders
    bool operator==(const set<T>&);
    bool operator!=(const set<T>&);
    bool operator<(const set<T>&);
    bool operator>(const set<T>&);
    bool operator<=(const set<T>&);
    bool operator>=(const set<T>&);
    void operator=(const set<T>&);
    set<T> operator+(const set<T>&);
    set<T> operator-(const set<T>&);
    set<T> operator*(const set<T>&);
    //cout overloader, prints out sets
    friend ostream& operator<<(ostream& stream, const set<T>& B){
        //empty set case
        if(B.isEmpty()){
            stream<<"{}"<<endl;
        }
        //existing set case
        else {
            //create vector to hold set B data
            vector<T> vB;
            B.toVector(vB);
            //printout data in set B
            stream<<"{";
            for(int i = 0;i<B.getSize()-1;i++){
                stream<<vB[i]<<", ";
            }
            stream<<vB[B.getSize()-1]<<"}"<<endl;
        }
        return stream;
    }
};
//constructor, initialize tree
template<class T> set<T>::set(){
    RBTree<T> tree;
}
//copy constructor, copy over tree
template<class T> set<T>::set(const set<T>& tmp){
    tree = tmp.tree;
}
//destructor, RB calls its destructor, nothing needed
template<class T> set<T>::~set(){}
//insertion function checks for existing node in tree, inserts if d.n.e
template<class T> void set<T>::insert(T val){
    if(find(val))
        return;
    tree.insert(val);
}
//isEmpty function returns if root = NIL in tree
template<class T> bool set<T>::isEmpty()const{
    return(tree.isEmpty())?true:false;
}
//get size function returns number of nodes in set
template<class T> int set<T>::getSize() const{
    return tree.getSize();
}
//clear function removes all data in tree, via RB kill function 
template<class T> void set<T>::clear(){
    tree.kill();
}
//find function returns bool if node value exists, via RB find
template<class T> bool set<T>::find(T val){
    return tree.find(val);
}
//erase function removes data with desired data, via RB remove
template<class T> void set<T>::erase(T val){
    tree.remove(val);
}
//toVector function clears vect and fills it with tree nodes inorder
template<class T> void set<T>::toVector(vector<T>& vect) const{
    vect.clear();
    vect = tree.toVector(vect);
}
//toArray function fills A with tree nodes inorder
template<class T> void set<T>::toArray(T*& A) const{
    A = tree.toArray(A);
}
//==overload compares if sets are equal
template<class T> bool set<T>::operator==(const set<T>& B){
    //check which set is bigger
    if(getSize()!=B.getSize())
        return false;
    //if sets are equal size
    else {
        vector<T> vA, vB;
        //put THIS trees vectors in vA
        toVector(vA);
        //put B trees vectors in vB
        B.toVector(vB);
        //check if trees are equal, node by node in vector
        for(int i = 0;i < getSize();i++){
            if(vA[i]!=vB[i])
                return false;
        }
    }
    //passes tests if made it to here
    return true;
}
//!=overload compares if sets are inequal
template<class T> bool set<T>::operator!=(const set<T>& B){
    //check which set is bigger
    if(getSize()!=B.getSize())
        return true;
    //if sets are equal size
    else {
        vector<T> vA, vB;
        //put THIS trees vectors in vA
        toVector(vA);
        //put B trees vectors in vB
        B.toVector(vB);
        //check if trees are equal, node by node in vector
        for(int i = 0;i < getSize();i++){
            if(vA[i]==vB[i])
                return false;
        }
    }
    //passes test if made it to here
    return true;
}
//< operator overload tests if A is subset of B
template<class T> bool set<T>::operator<(const set<T>& B){
    //make two variables for sizes of trees THIS and B
    int sizeA = getSize();
    int sizeB = B.getSize();
    //check if set A is not smaller than set B
    if(sizeA>=sizeB){
        return false;
    }
    //if set A is smaller
    else {
        vector<T> vA, vB;
        //tree A to vector vA
        toVector(vA);
        //tree B to vector vB
        B.toVector(vB);
        //j as "scoot"/"offset" variable 
        int j = 0;
        //for each value in smaller set, check for same node in B
        for(int i = 0; i<sizeA;i++){
            //if B has reached end of range
            if(j==sizeB)
                return false;
            //while tree B has not reached A's current check value
            //and tree B has not reached the end of range
            while(vA[i]>vB[j]&&j<sizeB)
                //offset through values in tree B
                j++;
            //if node in B does not exist to match A
            if(vA[i]!=vB[j])
                return false;
        }
    }
    //true if all nodes in A have a match in B
    return true;
}
//> operator overload tests if B is a subset of A
template<class T> bool set<T>::operator>(const set<T>& B){
    //check if set B is not smaller than set A
    if(getSize()<=B.getSize())
        return false;
    //if set B is smaller
    else {
        vector<T> vA, vB;
        //tree THIS to vector vA
        toVector(vA);
        //tree B to vector vB
        B.toVector(vB);
        //j as "scoot"/"offset" variable
        int j = 0;
        //for each value in smaller set, check for same node in A
        for(int i = 0; i<B.getSize();i++){
            //if A has reached end of range
            if(j==getSize())
                return false;
            //while tree A has not reached B's current check value
            //and tree A has not reached tthe end of range
            while(vA[j]<vB[i]&&j<getSize())
                //offset through values in tree A
                j++;
            //if node in A does not exist to match B
            if(vA[j]!=vB[i])
                return false;
        }
    }
    //true if all nodes in B have a match in A
    return true;
}
//<= overload, exact code as <operator except for first line
//refer for comments
template<class T> bool set<T>::operator<=(const set<T>& B){
    //check for if THIS tree IS LARGER
    if(getSize()>B.getSize())
        return false;
    //proceed only if B is larger or of same size
    else {
        vector<T> vA, vB;
        toVector(vA);
        B.toVector(vB);
        int j = 0;
        for(int i = 0; i<getSize();i++){
            if(j==B.getSize())
                return false;
            while(vA[i]>vB[j]&&j<B.getSize())
                j++;
            if(vA[i]!=vB[j])
                return false;
        }
    }
    return true;
}
//>= overload, exact code as >operator except for first line
//refer for comments
template<class T> bool set<T>::operator>=(const set<T>& B){
    //check for if B tree IS LARGER than A
    if(getSize()<B.getSize())
        return false;
    //proceed only if A is larger or of same size
    else {
        vector<T> vA, vB;
        toVector(vA);
        B.toVector(vB);
        int j = 0;
        for(int i = 0; i<B.getSize();i++){
            if(j==getSize())
                return false;
            while(vA[j]<vB[i]&&j<getSize())
                j++;
            if(vA[j]!=vB[i])
                return false;
        }
    }
    return true;
}
//assignment operator
template<class T> void set<T>::operator=(const set<T>& B){
    //clears THIS tree
    clear();
    vector<T> vB;
    //tree B to vector vB
    B.toVector(vB);
    //insert all values of B into THIS now empty tree
    for(int i = 0; i<B.getSize();i++){
        insert(vB[i]);
    }
}
//set addition operator
template<class T> set<T> set<T>::operator+(const set<T>& B){
    //create temp set
    set<T> tmp;
    vector<T> vB;
    //variable for size of B tree
    int sizeB = B.getSize();
    //tree B to vector vB
    B.toVector(vB);
    //insert all B nodes into temp
    for(int i = 0;i<sizeB;i++){
        tmp.insert(vB[i]);
    }
    vector<T> vA;
    //variable for size of THIS tree
    int sizeA = getSize();
    //THIS tree to vector vA
    toVector(vA);
    //insert all THIS nodes into temp
    for(int i = 0;i<sizeA;i++){
        tmp.insert(vA[i]);
    }
    return tmp;
}
//set difference operator
template<class T> set<T> set<T>::operator-(const set<T>& B){
    //create temp set
    set<T> tmp;
    vector<T> vA, vB;
    //variables for size of THIS and B tree
    int sizeA = getSize();
    int sizeB = B.getSize();
    //THIS and B tree to vectors vA and vB respectively
    toVector(vA);
    B.toVector(vB);
    //insert all A nodes into temp
    for(int i = 0;i<sizeA;i++){
        tmp.insert(vA[i]);
    }
    //remove all B nodes from temp (A values)
    for(int i = 0;i<sizeB;i++){
        tmp.erase(vB[i]);
    }
    return tmp;
}
//set intersection
template<class T> set<T> set<T>::operator*(const set<T>& B){
    //create temp set
    set<T> tmp;
    vector<T> vB;
    //variable for size of B tree
    int sizeB = B.getSize();
    //B tree to vector vB
    B.toVector(vB);
    //insert all B nodes into temp
    for(int i = 0;i<sizeB;i++){
        tmp.insert(vB[i]);
    }
    vector<T> v;
    //variable for size of temp/B tree
    int size = tmp.getSize();
    //B/temp tree to vector v
    tmp.toVector(v);
    //check THIS tree for all nodes of temp/B tree
    for(int i = 0;i<size;i++){
        //if temp exclusive node exists, delete it from temp
        if(!find(v[i]))
            tmp.erase(v[i]);
    }
    return tmp;
}
#endif /* RBTREE_H_ */
