// To perform Selection Sort
// Is Inplace, Is Not Stable

#include<iostream>
using namespace std;

//Selection sort
void selectionSort(int *arr, int n){
  for(int i = 0; i < n - 1 ; i++){
    int min = i;
    for(int j = i + 1; j < n; j++){
      if(arr[j] < arr[min]) min = j;
    }
    swap(arr[min], arr[i]);
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
  selectionSort(arr, n);
  print(arr,n);
}