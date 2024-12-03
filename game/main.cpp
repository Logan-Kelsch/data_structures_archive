//created by Logan Kelsch 2024
//
//
#include<iostream>

using namespace std;

int main(){
	cout<<"Hello World!\n\n";
	int num;
	cout<<"Please Enter array size: ";
	cin>>num;
	
	int i=1;

	while(i<num){
		++i*=2;
		i--;
		cout<<i<<endl;
	}
	i/=2;
	cout<<i<<endl;

	return 0;
}

