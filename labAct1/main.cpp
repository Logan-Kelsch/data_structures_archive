//Programmer: Logan Kelsch
//Worked With: Zach Christensen
//Date: 2/23/24

#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

template<class T> using compfct = T (*)(const T&, const T&);

template<class T> void sweep(T*, T*, T*, int, T(*)(const T&, const T&));

template<class T> T Min(const T&, const T&);
template<class T> T Max(const T&, const T&);
template<class T> void print(T&);

int main(){
	int arr1[7] = {2,5,6,9,10,1,1};
    int arr2[7] = {1,3,10,11,6,5,0};
    int arr3[7];
    
    sweep(arr1,arr2,arr3,7,Max);
    for_each(arr3,arr3+7,print<int>);
    cout<<endl;
    sweep(arr1,arr2,arr3,7,Min);
    for_each(arr3,arr3+7,print<int>);
    cout<<endl;
    
	return 0;
};

template<class T> void sweep(T* a1, T* a2, T* a3, int size, T(*compfct)(const T&, const T&)){
    for(int i=0;i<size;i++){
        *(a3+i)=compfct(*(a1+i),*(a2+i));
    }
}

template<class T> T Min(const T& a, const T& b){
    return(a<b)?a:b;
}
template<class T> T Max(const T& a, const T& b){
    return(a>b)?a:b;
}
template<class T> void print(T& val){
    cout<<val<<" ";
}
