//Programmer: Logan Kelsch
//Date: 3/1/24
//main.cpp function is for part 2 in homework number 4

#include <iostream>
#include <vector>

using namespace std;

//(a) templated T bool pointer function with using command referencing two templated constants T
template<class T> using funcPtr = bool (*)(const T&, const T&);
//command specific to part 2 of homework, is replacing the functionality of part 1 count functions
//using multiple temlpates P for template iteration and FCT template function pointer
template<class T, class P, class FCT> long count(P, P, const T&, FCT);
//greater equal function tests if var 1 is greater or equal to var 2 and returns t/f
template<class T> bool greaterEqual(const T&, const T&);


int main(){ 
    //lambda functions for less/greater/equal tests returns bool on two var comparisons
    auto Less = [](auto a, auto b) ->bool{return a<b;};
    auto Greater = [](auto a, auto b) ->bool{return a>b;};
    auto Equal = [](auto a, auto b) ->bool{return a==b;};
    //Arrays used in homework 4
    int arr1[7] = {2, 5, 6, 9, 10, 1, 1};
    double arr2[7] = {4, 4, 2, 9, 0, 3, 4};
    vector<int> vec1 = {2, 5, 6, 9, 10, 1, 1};
    vector<double> vec2 = {4, 4, 2, 9, 0, 3, 4};
    //beginning of printouts for all arrays and vector comparisons
    //all compared by less than, greater than, equal to, and greater/equal to
    cout<<"\nAll vectors and arrays compared to a value of (5)";
    //array 1 output
    cout<<"\n\nArray 1:";
    cout << "\n\tLess (5): " <<count<int>(arr1,arr1+7,5,Less);
    cout << "\n\tGreater (5): " <<count<int>(arr1,arr1+7,5,Greater);
    cout << "\n\tEqual (5): " <<count<int>(arr1,arr1+7,5,Equal);
    cout << "\n\tgreaterEqual (5): " <<count<int>(arr1,arr1+7,5,greaterEqual<int>);
    //array 2 output
    cout<<"\n\nArray 2:";
    cout << "\n\tLess (5): " <<count<double>(arr2,arr2+7,5,Less);
    cout << "\n\tGreater (5): " <<count<double>(arr2,arr2+7,5,Greater);
    cout << "\n\tEqual (5): " <<count<double>(arr2,arr2+7,5,Equal);
    cout << "\n\tgreaterEqual (5): " <<count<double>(arr2,arr2+7,5,greaterEqual<double>);
    //vector 1 output
    cout<<"\n\nVector 1:";
    cout << "\n\tLess (5): " <<count<int>(vec1.begin(),vec1.end(),5,Less);
    cout << "\n\tGreater (5): " <<count<int>(vec1.begin(),vec1.end(),5,Greater);
    cout << "\n\tEqual (5): " <<count<int>(vec1.begin(),vec1.end(),5,Equal);
    cout << "\n\tgreaterEqual (5): " <<count<int>(vec1.begin(),vec1.end(),5,greaterEqual<int>);
    //vector 2 output
    cout<<"\n\nVector 2:";
    cout << "\n\tLess (5): " <<count<double>(vec2.begin(),vec2.end(),5,Less);
    cout << "\n\tGreater (5): " <<count<double>(vec2.begin(),vec2.end(),5,Greater);
    cout << "\n\tEqual (5): " <<count<double>(vec2.begin(),vec2.end(),5,Equal);
    cout << "\n\tgreaterEqual (5): " <<count<double>(vec2.begin(),vec2.end(),5,greaterEqual<double>);
    //all structures within count call, including the less than or equal to lambda function in-line insertion
    cout<<"\n\nAll Structures - Lambda Parameter:";
    cout << "\n\tLessEqual (5): " <<count<int>(arr1,arr1+7,5,[](auto a, auto b)->bool{return a<=b;});
    cout << "\n\tLessEqual (5): " <<count<double>(arr2,arr2+7,5,[](auto a, auto b)->bool{return a<=b;});
    cout << "\n\tLessEqual (5): " <<count<int>(vec1.begin(),vec1.end(),5,[](auto a, auto b)->bool{return a<=b;});
    cout << "\n\tLessEqual (5): " <<count<double>(vec2.begin(),vec2.end(),5,[](auto a, auto b)->bool{return a<=b;});
    cout<<endl<<endl;
    return 0;
}
//greater equal function that tests two const if a is > or = to b
template<class T> bool greaterEqual(const T& a, const T& b){
    return a>=b;
}
//New count function replacement and combination using multiple templates in part two of this homework
//class P is iteration templat, T is comparison and values template, FCT is functionPointer template
//Nothing fundamentally has changed since part one of homework, as this operates the same.
template<class T, class P, class FCT> long count(P start, P end, const T& num, FCT funcPtr){
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
