//Main program file for driver application of alg time tests
//programmer: Logan Kelsch
//Date: 2/19/24 -- COMPLETED 2/20/24
//program framework modeled off of FunctionPointers004 by Dr. Spickler
//with significant removal and implication of code for specific use.
//main.cpp consists of main function and 4 sorting functions
//in which return the number of operations performed in each algorithm

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

//prototypes of each templated (T) sort function bringing in an array and size, returns
//number of operations performed through tally system
template <class T> long bubbleSort(T[], int);
template <class T> long selectionSort(T[], int);
template <class T> long insertionSort(T[], int);
template <class T> long bubbleSort2(T[], int);

int main() {
  srand(time(0));
  //function pointer array for all given sorting functions
  long (*fctptr[4])(int[], int);
  //Setting of all four sorting functions in function pointer
  fctptr[0] = bubbleSort;
  fctptr[1] = selectionSort;
  fctptr[2] = insertionSort;
  fctptr[3] = bubbleSort2;
  // Size of the array to sort.
  int num = 0;
  //user input for custom number of data points in set to order
  cout << "Input the number of values: ";
  cin >> num;
  // 3 vectors containing (1) randomized data, (2) ordered data, (3) reverese ordered data
  vector<int> data;
  vector<int> data2;
  vector<int> data3;
  //array in which all data will be passed pre-sorting, to allow for reuse of random data sets
  int *A = new int[num];
  // populating vector 1 with random data
  for (int i = 0; i < num; i++)
    data.push_back(rand());
  // populating vector 2 with oredered data
  for (int i = 0; i < num; i++)
      data2.push_back(i);
  // populating vector 3 with reverse oredered data
  for (int i = num; i>0; i--)
      data3.push_back(i);
  //longs used to collect and report number of operations per case
  long opsAvg = 0;
  long opsBest = 0;
  long opsWorst = 0;
  //for loop to run each algorithm
  for (int i = 0; i < 4; i++) {
    //copying randomized data set to array for sorting
    cout<<"Average Case:\n";
    copy(data.begin(), data.end(), A);
    opsAvg = fctptr[i](A, num);
    //console data output for randomized set
    cout << "\tOperations " << i << ": "
         << opsAvg / 1000000.0 << " Million Operations" << endl;
    //copying ordered data set to array for sorting
    cout<<"Best Case:\n";
    copy(data2.begin(), data2.end(), A);
    opsBest = fctptr[i](A, num);
    //console data output for ordered set
    cout << "\tOperations " << i << ": "
         << opsBest / 1000000.0 << " Million Operations" << endl;
    //copying reverse ordered data set to array for sorting
    cout<<"Worst Case:\n";
    copy(data3.begin(), data3.end(), A);
    opsWorst = fctptr[i](A, num);
    //console data output for reverse oredered set
    cout << "\tOperations " << i << ": "
         << opsWorst / 1000000.0 << " Million Operations" << endl;
  }
  delete[] A;
  return 0;
}
//provided bubble sort code inserted, takes in templated (T) array and size int of array
template <class T> long bubbleSort(T array[], int size) {
    long ops = 0;
  for(int i=0; i<size-1;i++){
      ops+=4;
      for(int j = 0; j<size-i-1; j++){
          ops+=5;
          if(array[j]>array[j+1]){
              ops+=7;
              T temp = array[j];
              array[j]=array[j+1];
              array[j+1]=temp;
          }
          ops++;
      }
      ops++;
  }
  ops++;
  return ops;
}
//provided selection sort code inserted, takes in templated (T) array and size int of array
template <class T> long selectionSort(T array[], int size) {
  int minIndex;
  long ops = 1;
  for (int i = 0; i < (size - 1); i++) {
    ops+=4;
    minIndex = i;
    ops++;
    for (int j = i + 1; j < size; j++){
      ops+=4;
      if (array[j] < array[minIndex]){
        ops++;
        minIndex = j;
        ops++;
      }
      ops++;
    }
    ops++;
    T val = array[i];
    array[i]=array[minIndex];
    array[minIndex]=val;
    ops+=3;
  }
  ops++;
  return ops;
}
//provided insertion sort code inserted, takes in templated (T) array and size int of array
template <class T> long insertionSort(T array[], int size) {
    long ops = 0;
  for (int i = 1; i < size; i++) {
    ops+=3;
    int j = 0;
    T val = array[i];
    ops+=2;
    for(j=i;j>0&&array[j-1]>val;j--){
        ops+=5;
        array[j]=array[j-1];
        ops+=2;
    }
    ops++;
    array[j]=val;
    ops++;
  }
  ops++;
  return ops;
}
//provided bubble sort 2 code inserted, takes in templated (T) array and size int of array
template <class T> long bubbleSort2(T data[], int n){
    bool again = true;
    long ops = 1;
    for(int i=0;i<n-1&&again;i++){
        ops+=5;
        for(int j=n-1,again=false;j>i;--j){
            ops+=5;
            if(data[j]<data[j-1]){
                ops+=2;
                swap(data[j],data[j-1]);
                again=true;
                ops+=5;
            }
            ops++;
        }
        ops++;
    }
    ops++;
    return ops;
}
//END OF CODE
