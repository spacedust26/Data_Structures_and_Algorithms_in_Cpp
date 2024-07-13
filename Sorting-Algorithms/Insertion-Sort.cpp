//To perform Insertion Sort
//Is Inplace Is Stable

#include<iostream>
using namespace std;

//Insertion Sort
void insertionSort(int *arr, int n){
  for(int i = 1; i < n ; i++){
    int temp = arr[i];
    int j;
    for(j =  i - 1; j >= 0; j--){
      if(arr[j] > temp) arr[j+1] = arr[j];
      else break;
    }
    arr[j+1] = temp;
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
  insertionSort(arr, n);
  print(arr,n);
}