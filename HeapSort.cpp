// C++ program for implementation of Heap Sort 
#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i)
{
  int largest = i;//initialize largest as root
  int  l = 2*i +1;//left child
  int r = 2*i +2;//right child
  //if left child is greater than root
  if(arr[l]>arr[largest] && l < n) {
      largest = l;
  }
  //if right child is greater than root
  if(arr[r] > arr[largest] && r < n){
          largest = r;
      }
      if(largest != i){
          swap(arr[i],arr[largest]);
          //Recursively heapify the affected subtree
          heapify(arr,n,largest);
  }
}

// main function to do heap sort 
void heapSort(int arr[], int n)
{ //Build max-heap
  for(int i = n/2 -1;i>=0;--i){
      heapify(arr,n,i);
  }
  //One by one extraction of elements from heap
  for(int i = n-1;i>=0;--i){
      swap(arr[0],arr[i]);
      heapify(arr,i,0);
  }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program 
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};//Unsorted
    int n = 6;//Size of array

    heapSort(arr, n);//Function Call

    cout << "Sorted array is \n";
    printArray(arr, n);
} 
