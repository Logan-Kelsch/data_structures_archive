//Programmer: Logan Kelsch
//Date: 4/22-23/24
//Project 2
//header+function file for multiSet 

#ifndef multiSet_H_
#define multiSet_H_

#include "RBTree.h"
#include <iostream>
#include <vector>

using namespace std;
//TEMPLATED multiSet CLASS
//all functions are written outside of braces, 
//except for << friend operator overloader
template<class T>
class multiSet {
private:
    //only private member, red-black tree
    RBTree<T> tree;
public:
    //constructor,copy constructor,destructor
    multiSet();
    multiSet(const multiSet<T>&);
    ~multiSet();
    //all other public call functions
    void insert(T);
    bool isEmpty()const;
    int getSize()const;
    void clear();
    void erase(T);
    bool find(T);
    int count(T);
    
    //MULTImultiSet MANIPULATIONS
    //>,< also considers frequencies
    //* intersection but only considers minumum frequencies
    
    void toVector(vector<T>&)const;
    void toArray(T*&)const;
    //overloaders
    bool operator==(const multiSet<T>&);
    bool operator!=(const multiSet<T>&);
    bool operator<(const multiSet<T>&);
    bool operator>(const multiSet<T>&);
    bool operator<=(const multiSet<T>&);
    bool operator>=(const multiSet<T>&);
    void operator=(const multiSet<T>&);
    multiSet<T> operator+(const multiSet<T>&);
    multiSet<T> operator-(const multiSet<T>&);
    multiSet<T> operator*(const multiSet<T>&);
    //cout overloader, prints out multiSets
    friend ostream& operator<<(ostream& stream, const multiSet<T>& B){
        //empty multiSet case
        if(B.isEmpty()){
            stream<<"{}"<<endl;
        }
        //existing multiSet case
        else {
            //create vector to hold multiSet B data
            vector<T> vB;
            B.toVector(vB);
            //printout data in multiSet B
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
template<class T> multiSet<T>::multiSet(){
    RBTree<T> tree;
}
//copy constructor, copy over tree
template<class T> multiSet<T>::multiSet(const multiSet<T>& tmp){
    tree = tmp.tree;
}
//destructor, RB calls its destructor, nothing needed
template<class T> multiSet<T>::~multiSet(){}
//count function returns tally of nodes with val
template<class T> int multiSet<T>::count(T val){
    return tree.count(val);
}
//insertion function checks for existing node in tree, inserts if d.n.e
template<class T> void multiSet<T>::insert(T val){
    tree.insert(val);
}
//isEmpty function returns if root = NIL in tree
template<class T> bool multiSet<T>::isEmpty()const{
    return(tree.isEmpty())?true:false;
}
//get size function returns number of nodes in multiSet
template<class T> int multiSet<T>::getSize() const{
    return tree.getSize();
}
//clear function removes all data in tree, via RB kill function 
template<class T> void multiSet<T>::clear(){
    tree.kill();
}
//find function returns bool if node value exists, via RB find
template<class T> bool multiSet<T>::find(T val){
    return tree.find(val);
}
//erase function removes data with desired data, via RB remove
template<class T> void multiSet<T>::erase(T val){
    tree.remove(val);
}
//toVector function clears vect and fills it with tree nodes inorder
template<class T> void multiSet<T>::toVector(vector<T>& vect) const{
    vect.clear();
    vect = tree.toVector(vect);
}
//toArray function fills A with tree nodes inorder
template<class T> void multiSet<T>::toArray(T*& A) const{
    A = tree.toArray(A);
}
//==overload compares if multiSets are equal
template<class T> bool multiSet<T>::operator==(const multiSet<T>& B){
    //check which multiSet is bigger
    if(getSize()!=B.getSize())
        return false;
    //if multiSets are equal size
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
//!=overload compares if multiSets are inequal
template<class T> bool multiSet<T>::operator!=(const multiSet<T>& B){
    //check which multiSet is bigger
    if(getSize()!=B.getSize())
        return true;
    //if multiSets are equal size
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
//< operator overload tests if A is submultiSet of B
template<class T> bool multiSet<T>::operator<(const multiSet<T>& B){
    //make two variables for sizes of trees THIS and B
    int sizeA = getSize();
    int sizeB = B.getSize();
    //check if multiSet A is not smaller than multiSet B
    if(sizeA>=sizeB){
        return false;
    }
    //if multiSet A is smaller
    else {
        vector<T> vA, vB;
        //tree A to vector vA
        toVector(vA);
        //tree B to vector vB
        B.toVector(vB);
        //j as "scoot"/"offmultiSet" variable 
        int j = 0;
        //for each value in smaller multiSet, check for same node in B
        for(int i = 0; i<sizeA;i++){
            //if B has reached end of range
            if(j==sizeB)
                return false;
            //while tree B has not reached A's current check value
            //and tree B has not reached the end of range
            while(vA[i]>vB[j]&&j<sizeB)
                //offmultiSet through values in tree B
                j++;
            //if node in B does not exist to match A
            if(vA[i]!=vB[j])
                return false;
        }
    }
    //true if all nodes in A have a match in B
    return true;
}
//> operator overload tests if B is a submultiSet of A
template<class T> bool multiSet<T>::operator>(const multiSet<T>& B){
    //check if multiSet B is not smaller than multiSet A
    if(getSize()<=B.getSize())
        return false;
    //if multiSet B is smaller
    else {
        vector<T> vA, vB;
        //tree THIS to vector vA
        toVector(vA);
        //tree B to vector vB
        B.toVector(vB);
        //j as "scoot"/"offmultiSet" variable
        int j = 0;
        //for each value in smaller multiSet, check for same node in A
        for(int i = 0; i<B.getSize();i++){
            //if A has reached end of range
            if(j==getSize())
                return false;
            //while tree A has not reached B's current check value
            //and tree A has not reached tthe end of range
            while(vA[j]<vB[i]&&j<getSize())
                //offmultiSet through values in tree A
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
template<class T> bool multiSet<T>::operator<=(const multiSet<T>& B){
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
template<class T> bool multiSet<T>::operator>=(const multiSet<T>& B){
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
template<class T> void multiSet<T>::operator=(const multiSet<T>& B){
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
//multiSet addition operator, max frequency is preserved
template<class T> multiSet<T> multiSet<T>::operator+(const multiSet<T>& B){
    //create temp multiSet
    multiSet<T> tmp;
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
    //insert all THIS nodes into temp while
    //watching for max frequency preservance
    //skip variable counts how much frequency to skip
    int skip = 0;
    //for all nodes in THIS tree
    for(int i = 0;i<sizeA;i++){
        //if matching node already exists in tmp
        if(tmp.find(vA[i])){
            //if there are more to be inserted than exist
            if(count(vA[i])>tmp.count(vA[i])){
                
                //skip i forward max frequency times
                i+=tmp.count(vA[i]);
                //count number of remaining inserts 
                //for max frequency preservance
                skip = count(vA[i])-tmp.count(vA[i]);
                //for all remaining inserts
                for(int n = skip;n>0;n--){
                    tmp.insert(vA[i]);
                    i++;
                }
                i--;
            }
            //if higher frequency than needs inserted
            else {
                //skip remaining values to insert
                i+=count(vA[i])-1;
            }
        }
        //if no matching nodes already exist in temp
        else{
            for(int n = count(vA[i]);n>0;n--){
                tmp.insert(vA[i]);
                i++;
            }
            i--;
        }
            
        //reset skip value
        skip = 0;
    }
    return tmp;
}
//multiSet difference operator
template<class T> multiSet<T> multiSet<T>::operator-(const multiSet<T>& B){
    //create temp multiSet
    multiSet<T> tmp;
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
//multiSet intersection
template<class T> multiSet<T> multiSet<T>::operator*(const multiSet<T>& B){
    //create temp multiSet
    multiSet<T> tmp;
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
        else {
            if(count(v[i])<tmp.count(v[i])){
                //cout<<count(v[i])<<":"<<tmp.count(v[i])<<" in A:B"<<endl;
                int diff = tmp.count(v[i])-count(v[i]);
                //cout<<diff<<" more in B than A"<<endl;
                for(int n = diff; n>0;n--)
                    tmp.erase(v[i]);
            }
        }
    }
    return tmp;
}
#endif /* RBTREE_H_ */
