//To perform merge sort
//Is Stable, Not Inplace

#include<iostream>
using namespace std;
int c = 0;

//merge
void merge(int *arr, int s, int e){
  int mid = s + (e-s)/2;
  int len1 = mid - s + 1;
  int len2 = e - mid;
  int *first = new int[len1];
  int *second = new int[len2];

  int arrIndex = s;
  for(int i = 0; i < len1 ; i++){
    first[i] = arr[arrIndex++];
  }
  arrIndex = mid + 1;
  for(int i = 0; i < len2 ; i++){
    second[i] = arr[arrIndex++];
  }

  int index1 = 0, index2 = 0;
  arrIndex = s;
  while(index1 < len1 && index2 < len2){
    if(first[index1] < second[index2]){
      arr[arrIndex++] = first[index1++];
    }else{
      arr[arrIndex++] = second[index2++];
      c += len1 - index1;
      for (int i = index1; i < len1; i++) {
        printf("Inversion pair: (%d, %d)\n", first[i], second[index2-1]);
      }
      printf("Round done\n");
    }
  }

  while(index1 < len1){
    arr[arrIndex++] = first[index1++];
  }
  while(index2 < len2){
    arr[arrIndex++] = second[index2++];
  }

  delete []first;
  delete []second;
}

//mergesort
void mergeSort(int *arr, int s, int e){
  if(s >= e) return;
  int mid = s + (e - s) / 2;
  mergeSort(arr,s, mid);
  mergeSort(arr,mid+1,e);
  merge(arr,s,e);
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
  mergeSort(arr,0,n-1);
  print(arr,n);
  printf("Count of inversions: %d", c);
}