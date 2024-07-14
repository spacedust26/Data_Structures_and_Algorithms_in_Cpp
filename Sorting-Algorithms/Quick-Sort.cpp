//To perform quick sort
//Not Stable, Is Inplace

#include<iostream>
using namespace std;

//quick
int quick(int *arr, int s, int e){
  int count = 0;
  int pivot = arr[s];
  for(int i = s+1 ; i<=e ;i++){
    if(arr[i] <= pivot) count++;
  }
  int pivotIndex = s + count;
  swap(arr[s], arr[pivotIndex]);
  int i = s, j = e;
  while(i < pivotIndex && j > pivotIndex){
    while(arr[i] <= arr[pivotIndex]) i++;
    while(arr[j] > arr[pivotIndex]) j--;
    if(i < pivotIndex && j > pivotIndex){
      swap(arr[i], arr[j]);
    }
  }
  return pivotIndex;
}

//quicksort
void quickSort(int *arr, int s, int e){
  if(s >= e) return;
  int partition = quick(arr, s, e);
  quickSort(arr,s,partition-1);
  quickSort(arr,partition+1,e);
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
  quickSort(arr,0,n-1);
  print(arr,n);
}