//Programmer: Logan Kelsch
//HOMEWORK09

#ifndef HASHTABLE_H_
#define HASHTABLE_H_

#include <iostream>
#include "ListOfLists.h"

using namespace std;

template <class T> class HashTable {
protected:
  ListOfLists<T> tab;
  int (*hf)(T &);
public:
  HashTable(int sz, int (*hashfct)(T &));
  virtual ~HashTable();
  void insert(T);
  void remove(T);
  bool find(T);
  void rehash(int sz);
  void print();
};
//create table
template <class T>
HashTable<T>::HashTable(int sz, int (*hashfct)(T &)) {
  hf = hashfct;
  vector<T> E;
  //fill tab with empty vectors
  for (int i = 0; i < sz; i++)
    tab.push_back(E);
}
//nothing needed as there are no pointers
template <class T> HashTable<T>::~HashTable() { }
//insertion function
template <class T> void HashTable<T>::insert(T item) {
  int pos = hf(item) % tab.size();
  //add item to vector of mod locations
  tab[pos].push_back(item);
}
//removes requested item if exists
template <class T> void HashTable<T>::remove(T item) {
  int pos = hf(item) % tab.size();
  int pos2 = -1;
  //checks through calculated home vector
  for(size_t i = 0; i < tab[pos].size();i++)
      if(tab[pos][i]==item)
          pos2 = static_cast<int>(i);
  //if matching location was found
  if(pos2!=-1)
    tab[pos].erase(tab[pos].begin()+pos2);
}
//find function finds requested value
template <class T> bool HashTable<T>::find(T item) {
  int pos = hf(item) % tab.size();
  //checks through calculated home vector
  for(size_t i = 0; i < tab[pos].size();i++)
      if(tab[pos][i]==item)
          return true;
  return false;
}
//rehash function creates new hash table of new size
template <class T> void HashTable<T>::rehash(int sz) {
  HashTable<T> newtable(sz, hf);
  //for all values of old table, insert to new table
  for(size_t i = 0; i<tab.size();i++){
        for(size_t j = 0; j<tab[i].size();j++){
            T item = tab[i][j];
            newtable.insert(item);
        }
  }
  //copy over table to home variable
  tab = newtable.tab;
}
//print out all variables of table
template <class T> void HashTable<T>::print() {
  for (size_t i = 0; i < tab.size(); i++){
    cout << i << ": ";
    if(!tab[i].empty())
        for(size_t j = 0; j<tab[i].size();j++)
            cout << tab[i][j] << " ";
    cout << endl;
  }
}

#endif /* HASHTABLE_H_ */
