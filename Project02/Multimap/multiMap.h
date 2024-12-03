//Programmer: Logan Kelsch
//Date: 4/22-23/24
//Project 2
//header+function file for multiMap 

#ifndef multiMap_H_
#define multiMap_H_

#include "RBTree.h"
#include <iostream>
#include <vector>
#include <utility>

using namespace std;
//TEMPLATED multiMap CLASS
//all functions are written outside of braces, 
//except for << friend operator overloader
template<class T>
class multiMap {
private:
    //only private member, red-black tree
    RBTree<T> tree;
public:
    //constructor,copy constructor,destructor
    multiMap();
    multiMap(const multiMap<T>&);
    ~multiMap();
    //all other public call functions
    void insert(pair<int,T>);
    bool isEmpty()const;
    int getSize()const;
    void clear();
    void erase(pair<int,T>);
    bool find(int);
    void toVector(vector<pair<int,T>>&)const;
    void toArray(pair<int,T>*&)const;
    vector<T> get(int);
    void set(int,T);
    int count(int val)const;
    
    //overloaders
    bool operator==(const multiMap<T>&);
    bool operator!=(const multiMap<T>&);
    void operator=(const multiMap<T>&);
    //cout overloader, prints out multiMaps
    friend ostream& operator<<(ostream& stream, const multiMap<T>& B){
        int cnt = 0;
        //empty multiMap case
        if(B.isEmpty()){
            stream<<"{}"<<endl;
        }
        //existing multiMap case
        else {
            //create vector to hold multiMap B data
            vector<pair<int,T>> vB;
            B.toVector(vB);
            //printout data in multiMap B
            stream<<"{ ";
            for(int i = 0;i<B.getSize();i++){
                cnt = B.count(vB[i].first);
                stream<<"{"<<vB[i].first<<", ";
                for(int n = cnt-1;n>0;n--){
                    stream<<vB[i].second<<" / ";
                    i++;
                }
                stream<<vB[i].second<<"} ";
            }
            stream<<"}"<<endl;
        }
        return stream;
    }
};
//constructor, initialize tree
template<class T> multiMap<T>::multiMap(){
    RBTree<T> tree;
}
//copy constructor, copy over tree
template<class T> multiMap<T>::multiMap(const multiMap<T>& tmp){
    tree = tmp.tree;
}
//destructor, RB calls its destructor, nothing needed
template<class T> multiMap<T>::~multiMap(){}
//count function returns tally of nodes with val
template<class T> int multiMap<T>::count(int val)const{
    return tree.count(val);
}
//get function returns pair value to input key
template<class T> vector<T> multiMap<T>::get(int val){
    return tree.retValue(val);
}
//set function does insertion via two seperate inputs
template<class T> void multiMap<T>::set(int val1, T val2){
    pair<int, T> tmp;
    tmp.first = val1;
    tmp.second = val2;
    insert(tmp);
}
//insertion function checks for existing node in tree, inserts if d.n.e
template<class T> void multiMap<T>::insert(pair<int,T> val){
    tree.insert(val);
}
//isEmpty function returns if root = NIL in tree
template<class T> bool multiMap<T>::isEmpty()const{
    return(tree.isEmpty())?true:false;
}
//get size function returns number of nodes in multiMap
template<class T> int multiMap<T>::getSize() const{
    return tree.getSize();
}
//clear function removes all data in tree, via RB kill function 
template<class T> void multiMap<T>::clear(){
    tree.kill();
}
//find function returns bool if node value exists, via RB find
template<class T> bool multiMap<T>::find(int val){
    return tree.find(val);
}
//erase function removes data with desired data, via RB remove
template<class T> void multiMap<T>::erase(pair<int,T> val){
    tree.remove(val);
}
//toVector function clears vect and fills it with tree nodes inorder
template<class T> void multiMap<T>::toVector(vector<pair<int,T>>& vect) const{
    vect.clear();
    vect = tree.toVector(vect);
}
//toArray function fills A with tree nodes inorder
template<class T> void multiMap<T>::toArray(pair<int,T>*& A) const{
    A = tree.toArray(A);
}
//==overload compares if multiMaps are equal
template<class T> bool multiMap<T>::operator==(const multiMap<T>& B){
    //check which multiMap is bigger
    if(getSize()!=B.getSize())
        return false;
    //if multiMaps are equal size
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
//!=overload compares if multiMaps are inequal
template<class T> bool multiMap<T>::operator!=(const multiMap<T>& B){
    //check which multiMap is bigger
    if(getSize()!=B.getSize())
        return true;
    //if multiMaps are equal size
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
template<class T> void multiMap<T>::operator=(const multiMap<T>& B){
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
