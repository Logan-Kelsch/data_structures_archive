//Programmer: Logan Kelsch
//Date: 2/23/24
//main.cpp function is for final part in homework number 3

#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>

using namespace std;
//(b.1) count function for counting true cases in vector
template<class T> long count(typename vector<T>::iterator, typename vector<T>::iterator, const string&, bool (*)(const T&, const T&));
//(2b) function pointer to connect alter to test functions
using funcPtr = void (*)(string&);
//alter function to alter the vector data based off of requested function
template<class T> void alter1(typename vector<T>::iterator, typename vector<T>::iterator, void (*)(T&));
/*
 * ucase - [brings in string](returns string all upper)
 * lcase - [brings in string](returns string all lower)
 * ucaseref - [bring in string&](void,turns all upper)
 * lcaseref - [bring in string&](void, turns all lower)
 * substrto - [bring in 2 strings](returns substring if sub in full string)
 * hassubstr - [bring in 2 const strings&](bool, if sub is in full string)
 * startswith - [bring in 2 const strings&](bool, if sub is front of full)
 * endswith - [bring in 2 const strings&](bool, if sub is back of full)
 */
string ucase(string);
string lcase(string);
void ucaseref(string&);
void lcaseref(string&);
string substrto(const string, const string);
bool hassubstr(const string&, const string&);
bool startswith(const string&, const string&);
bool endswith(const string&, const string&);


int main(){ 
    //opening file name per request of user
    string name = "";
    cout<<"Please enter file name: ";
    cin>>name;
    //if does not exist
    if(name!="dict"){
        cout<<"\n\n\tNO FILE FOUND: PLEASE RESTART PROGRAM.\n";
        return 0;
    }
    //data fector
    vector<string> dictA;
    //"in" is data input
    ifstream in;
    in.open(name);
    //rawline in raw data input
    string rawLine;
    in>>rawLine;
    //iterator
    int i = 0;
    //where there are still more lines
    while(!in.eof()){
        dictA.push_back(rawLine);
        in>>rawLine;
        i++;
    }
    //turn all lines into upper case
    alter1(dictA.begin(),dictA.end(),ucaseref);
    int size = dictA.size();
    //for entire vector, remove forward slash and all after
    for(int i = 0;i<size;i++){
        dictA[i] = substrto(dictA[i],"/");
    }
    //OUTPUT SECTION OF MAIN
    //tests words with THE
    long cnt = count(dictA.begin(),dictA.end(),"THE",hassubstr);
    cout<<"Words containing 'THE': "<<cnt<<endl;
    //words ending with ER
    cnt = count(dictA.begin(),dictA.end(),"ER",endswith);
    cout<<"Ends with 'ER': "<<cnt<<endl;
    //words starting with THE
    cnt = count(dictA.begin(),dictA.end(),"THE",startswith);
    cout<<"Starts with 'THE': "<<cnt<<endl;
    //Specific first letter tests
    cnt = count(dictA.begin(),dictA.end(),"T",startswith);
    cout<<"Starts with 'T': "<<cnt<<endl;
    string letQ[] = {"Q","R","S","T","U"};
    cnt=0;
    //for loop to iterate letters
    for(int i=0;i<5;i++){
        cnt += count(dictA.begin(),dictA.end(),letQ[i],startswith);
    }
    cout<<"Starts with 'Q'->'U': "<<cnt<<endl;
    string letA[] = {"A","B","C","D","E","F","G","H","I","J","K","L","M"};
    cnt=0;
    for(int i=0;i<13;i++){
        cnt += count(dictA.begin(),dictA.end(),letA[i],startswith);
    }
    cout<<"Starts with 'A'->'M': "<<cnt<<endl;
    in.close();
    return 0;
}
//returns string into upper case reference
string ucase(string & word){
    word=word.c_str();
    int i = 0;
    while(word[i]){
        word[i] = toupper(word[i]);
        i++;
    }
    return word;
}
//returns letters lowercase per reference
string lcase(string & word){
    word=word.c_str();
    int i = 0;
    while(word[i]){
        word[i] = tolower(word[i]);
        i++;
    }
    return word;
}
//switches string to upper case
void ucaseref(string & word){
    word=word.c_str();
    int i = 0;
    while(word[i]){
        word[i] = toupper(word[i]);
        i++;
    }
}
//switches string to lower case
void lcaseref(string & word){
    word=word.c_str();
    int i = 0;
    while(word[i]){
        word[i] = tolower(word[i]);
        i++;
    }
}
//returns string if substring exists in string
string substrto(const string word, const string sub){
    const char* cWord = word.c_str();
    const char* cSub = sub.c_str();
    char cutWord[30] = {};
    //if does not contain substring
    if(!hassubstr(word,sub))
        return word;
    //if contains backslash
    if(sub=="/"){
        int i = 0;
        while(cWord[i]!='/'&&cWord[i]!='\0'){
            cutWord[i]=cWord[i];
            i++;
        }
        cutWord[i]='\0';
        return cutWord;
    }
    return "";
}
//returns if substring is in string
bool hassubstr(const string& word, const string& sub){
    if(word.length()<sub.length())
        return false;
    int found = word.find(sub);
    return (found==-1)?false:true;
}
//returns if substring is at front of string
bool startswith(const string& word, const string& sub){
    if(!hassubstr(word,sub))
        return false;
    const char* cword = word.c_str();
    const char* csub = sub.c_str();
    int i = 0;
    bool matching = true;
    while(csub[i]!='\0'){
        if(csub[i]!=cword[i])
            return false;
        i++;
    }
    return true;
}
//returns if substrung is at back of string
bool endswith(const string& word, const string& sub){
    if(!hassubstr(word,sub))
        return false;
    const char* cword = word.c_str();
    const char* csub = sub.c_str();
    int subL = sub.length();
    int wordL = word.length();
    int i = 1;
    bool matching = true;
    while(csub[subL-i]!='\0'){
        if(csub[subL-i]!=cword[wordL-i])
            return false;
        i++;
    }
    return true;
}

//alters vector data per requeset of user
template<class T> void alter1(typename vector<T>::iterator start, typename vector<T>::iterator end, void (*funcPtr)(T&)){
    while(start!=end){
        funcPtr(*start);
        start++;
    }
}

//count function for vectors(b.2)
template<class T> long count(typename vector<T>::iterator start, typename vector<T>::iterator end, const string& val, bool (*funcPtr)(const T&, const T&)){
    long count = 0;
    //while testing variables is still within the vector
    while(start!=end){
        //if start compared to num is true as requested in main
        if(funcPtr(*start,val))
            count++;
        start++;
    }
    return count;
}
