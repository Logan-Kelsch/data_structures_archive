//Programmer: Logan Kelsch
//Date: 4/22-23/24
//Project 2
//header+function file for map 

#ifndef MAP_H_
#define MAP_H_

#include "RBTree.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
//TEMPLATED map CLASS
//all functions are written outside of braces, 
//except for << friend operator overloader
template<class T>
class map {
private:
    //only private member, red-black tree
    RBTree<T> tree;
public:
    //constructor,copy constructor,destructor
    map();
    map(const map<T>&);
    ~map();
    //all other public call functions
    void insert(pair<int,T>);
    bool isEmpty()const;
    int getSize()const;
    void clear();
    void erase(pair<int,T>);
    bool find(int);
    void toVector(vector<pair<int,T>>&)const;
    void toArray(pair<int,T>*&)const;
    T get(int);
    void set(int,T);
    
    //overloaders
    bool operator==(const map<T>&);
    bool operator!=(const map<T>&);
    void operator=(const map<T>&);
    //cout overloader, prints out maps
    friend ostream& operator<<(ostream& stream, const map<T>& B){
        //empty map case
        if(B.isEmpty()){
            stream<<"{}"<<endl;
        }
        //existing map case
        else {
            //create vector to hold map B data
            vector<pair<int,T>> vB;
            B.toVector(vB);
            //printout data in map B
            stream<<"{ ";
            for(int i = 0;i<B.getSize()-1;i++){
                stream<<"{"<<vB[i].first<<", "<<vB[i].second<<"} , ";
            }
            stream<<"{"<<vB[B.getSize()-1].first<<", "<<vB[B.getSize()-1].second<<"} }"<<endl;
        }
        return stream;
    }
};
//constructor, initialize tree
template<class T> map<T>::map(){
    RBTree<T> tree;
}
//copy constructor, copy over tree
template<class T> map<T>::map(const map<T>& tmp){
    tree = tmp.tree;
}
//destructor, RB calls its destructor, nothing needed
template<class T> map<T>::~map(){}
//get function returns pair value to input key
template<class T> T map<T>::get(int val){
    return tree.retValue(val);
}
//set function does insertion via two seperate inputs
template<class T> void map<T>::set(int val1, T val2){
    pair<int, T> tmp;
    tmp.first = val1;
    tmp.second = val2;
    insert(tmp);
}
//insertion function checks for existing node in tree, inserts if d.n.e
template<class T> void map<T>::insert(pair<int,T> val){
    tree.insert(val);
}
//isEmpty function returns if root = NIL in tree
template<class T> bool map<T>::isEmpty()const{
    return(tree.isEmpty())?true:false;
}
//get size function returns number of nodes in map
template<class T> int map<T>::getSize() const{
    return tree.getSize();
}
//clear function removes all data in tree, via RB kill function 
template<class T> void map<T>::clear(){
    tree.kill();
}
//find function returns bool if node value exists, via RB find
template<class T> bool map<T>::find(int val){
    return tree.find(val);
}
//erase function removes data with desired data, via RB remove
template<class T> void map<T>::erase(pair<int,T> val){
    tree.remove(val);
}
//toVector function clears vect and fills it with tree nodes inorder
template<class T> void map<T>::toVector(vector<pair<int,T>>& vect) const{
    vect.clear();
    vect = tree.toVector(vect);
}
//toArray function fills A with tree nodes inorder
template<class T> void map<T>::toArray(pair<int,T>*& A) const{
    A = tree.toArray(A);
}
//==overload compares if maps are equal
template<class T> bool map<T>::operator==(const map<T>& B){
    //check which map is bigger
    if(getSize()!=B.getSize())
        return false;
    //if maps are equal size
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
//!=overload compares if maps are inequal
template<class T> bool map<T>::operator!=(const map<T>& B){
    //check which map is bigger
    if(getSize()!=B.getSize())
        return true;
    //if maps are equal size
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
//assignment operator
template<class T> void map<T>::operator=(const map<T>& B){
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
#endif /* RBTREE_H_ */
