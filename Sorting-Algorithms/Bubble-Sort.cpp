// To perform Bubble Sort using the normal approach and the optimised approach
// Is Inplace, Is Stable

#include<iostream>
using namespace std;

//Bubble Sort - Normal approach
void bubbleSort(int *arr, int n){
  for(int i = 0; i < n - 1 ; i++){
    for(int j = 0; j < n - i - 1; j++){
      if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
    }
  }
}

//Bubble Sort - Optimised approach
void bubbleSortOptimised(int *arr, int n){
  bool flag = 0;
  for(int i = 0; i < n - 1 ; i++){
    for(int j = 0; j < n - i - 1; j++){
      if(arr[j] > arr[j+1]) {
        swap(arr[j], arr[j+1]);
        flag = 1;
      }
    }
    if(flag == 0) return;
  }
}

//Prints all the array elements
void print(int arr[], int n){
  cout << endl << "Printing the array elements: ";
  for(int i = 0; i < n ; i++){
    cout << arr[i] << " ";
  }
}

//Main function
int main(){
  int n;
  cout << "Enter array limit: ";
  cin >> n;
  int arr[20];
  cout << "Enter the array elements: ";
  for(int i = 0 ; i < n ; i++){
    cin >> arr[i];
  }
  // bubbleSort(arr, n);
  // print(arr,n);
  bubbleSortOptimised(arr, n);
  print(arr, n);
}