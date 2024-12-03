//Programmer: Logan Kelsch
//Date: 2/22/24
//main.cpp function is for part 1 in homework number 3

#include <iostream>
#include <vector>

using namespace std;

//(a) templated T bool pointer function with using command referencing two templated constants T
template<class T> using funcPtr = bool (*)(const T&, const T&);
//(b.1) count function used for tallying matching values in arrays
template<class T> long count(const T*, const T*, const T&, bool (*)(const T&, const T&));
//(c.1) count function used for tallying matching values in vectors
template<class T> long count(typename vector<T>::iterator, typename vector<T>::iterator, const T&, bool (*)(const T&, const T&));
//three templated bool functions comparing values of two variables
template<class T> bool Equal(const T&, const T&);
template<class T> bool Less(const T&, const T&);
template<class T> bool Greater(const T&, const T&);

//Main function ripped from homework03.pdf
//EXPECTED OUTPUT: 4 2 3 3 2 3 3 1
int main(){ 
    //Arrays for example.
    int arr1[7] = {2, 5, 6, 9, 10, 1, 1};
    int arr2[7] = {4, 4, 2, 9, 0, 3, 4};
    long num = count(arr1, arr1 + 7, 3, Greater);
    cout<<num<<endl;
    num=count(arr1,arr1+7,1,Equal);
    cout<<num<<endl;
    num=count(arr2,arr2+7,4,Equal);
    cout<<num<<endl;
    num = count(arr2, arr2 + 7, 4, Less);
    cout << num << endl;
    
    // Vectors for example.
    vector<int> vec1 = {2, 5, 6, 9, 10, 1, 1};
    vector<int> vec2 = {4, 4, 2, 9, 0, 3, 4};
    num = count(vec1.begin(), vec1.end(), 1, Equal);
    cout << num << endl;
    num = count(vec2.begin(), vec2.end(), 4, Equal);
    cout << num << endl;
    num = count(vec2.begin(), vec2.end(), 4, Less);
    cout << num << endl;
    num = count(vec2.begin(), vec2.end(), 4, Greater);
    cout << num << endl;
    return 0;
}
//bool function tests if first of templated variables is equal to second
template<class T> bool Equal(const T& a, const T& b){
    return (a==b)?true:false;
}
//bool function tests is first of templated variables is less than second
template<class T> bool Less(const T& a, const T& b){
    return (a<b)?true:false;
}
//bool function tests if first of templated variables is greater than second
template<class T> bool Greater(const T& a, const T& b){
    return (a>b)?true:false;
}
//count function for arrays (b.1)
template<class T> long count(const T* start, const T* end, const T& num, bool (*funcPtr)(const T&, const T&)){
    long count = 0;
    //while testing variable is still within the array
    while(start!=end){
        //if start compared to num is true as requested in main
        if(funcPtr(*start,num))
            count++;
        start++;
    }
    return count;
}
//count function for vectors(b.2)
template<class T> long count(typename vector<T>::iterator start, typename vector<T>::iterator end, const T& num, bool (*funcPtr)(const T&, const T&)){
    long count = 0;
    //while testing variables is still within the vector
    while(start!=end){
        //if start compared to num is true as requested in main
        if(funcPtr(*start,num))
            count++;
        start++;
    }
    return count;
}
