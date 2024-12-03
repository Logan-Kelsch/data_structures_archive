//Main program file for driver application of alg time tests
//programmer: Logan Kelsch
//Date: 2/19/24 -- COMPLETED 2/20/24
//program framework modeled off of FunctionPointers004 by Dr. Spickler
//with significant removal and implication of code for specific use.
//main.cpp consists of main function and 4 sorting functions.

#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;
using namespace std::chrono;

//prototypes of each templated (T) sort function bringing in an array and size
template <class T> void bubbleSort(T[], int);
template <class T> void selectionSort(T[], int);
template <class T> void insertionSort(T[], int);
template <class T> void bubbleSort2(T[], int);

int main() {
  srand(time(0));
  //function pointer array for all given sorting functions
  void (*fctptr[4])(int[], int);
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
  //for loop to run each algorithm
  for (int i = 0; i < 4; i++) {
    //copying randomized data set to array for sorting
    cout<<"Average Case Program:\n";
    auto start = high_resolution_clock::now();
    copy(data.begin(), data.end(), A);
    fctptr[i](A, num);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //console data output for randomized set
    cout << "Time to sort with algorithm " << i << ": "
         << duration.count() / 1000000.0 << " seconds" << endl;
    //copying ordered data set to array for sorting
    cout<<"Best Case Program:\n";
    start = high_resolution_clock::now();
    copy(data2.begin(), data2.end(), A);
    fctptr[i](A, num);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //console data output for ordered set
    cout << "Time to sort with algorithm " << i << ": "
         << duration.count() / 1000000.0 << " seconds" << endl;
    //copying reverse ordered data set to array for sorting
    cout<<"Worst Case Program:\n";
    start = high_resolution_clock::now();
    copy(data3.begin(), data3.end(), A);
    fctptr[i](A, num);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    //console data output for reverse oredered set
    cout << "Time to sort with algorithm " << i << ": "
         << duration.count() / 1000000.0 << " seconds" << endl;
  }
  delete[] A;
  return 0;
}
//provided bubble sort code inserted, takes in templated (T) array and size int of array
template <class T> void bubbleSort(T array[], int size) {
  for(int i=0; i<size-1;i++){
      for(int j = 0; j<size-i-1; j++){
          if(array[j]>array[j+1]){
              T temp = array[j];
              array[j]=array[j+1];
              array[j+1]=temp;
          }
      }
  }
}
//provided selection sort code inserted, takes in templated (T) array and size int of array
template <class T> void selectionSort(T array[], int size) {
  int minIndex;
  for (int i = 0; i < (size - 1); i++) {
    minIndex = i;
    for (int j = i + 1; j < size; j++)
      if (array[j] < array[minIndex])
        minIndex = j;
    T val = array[i];
    array[i]=array[minIndex];
    array[minIndex]=val;
  }
}
//provided insertion sort code inserted, takes in templated (T) array and size int of array
template <class T> void insertionSort(T array[], int size) {
  for (int i = 1; i < size; i++) {
    int j = 0;
    T val = array[i];
    for(j=i;j>0&&array[j-1]>val;j--)
        array[j]=array[j-1];
    array[j]=val;
  }
}
//provided bubble sort 2 code inserted, takes in templated (T) array and size int of array
template <class T> void bubbleSort2(T data[], int n){
    bool again = true;
    for(int i=0;i<n-1&&again;i++)
        for(int j=n-1,again=false;j>i;--j)
            if(data[j]<data[j-1]){
                swap(data[j],data[j-1]);
                again=true;
            }
}
//END OF CODE
