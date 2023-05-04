#include <iostream>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   // build heapify
  
  int leftNode = 2*root + 1;
  int rightNode = 2*root + 2;
  int max = 0;

  if (leftNode < n && arr[leftNode] > arr[root])
  {
      max = leftNode;
  }
  else
  {
      max = root;
  }

  if (rightNode < n && arr[rightNode] > arr[max])
  {
      max = rightNode;
  }

  if (max != root)
  {
      int temp = arr[root];
      arr[root] = arr[max];
      arr[max] = temp;
      heapify(arr, n, max);
  }
   
}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap

   for (int i = n / 2 - 1; i >= 0; i--)
   {
      heapify(arr, n, i);
   }
  
   // extracting elements from heap one by one
   
   for (int i = n-1; i >= 0; i--)
   {
      int temp = arr[0];
      arr[0] = arr[i];
      arr[i] = temp;
      heapify(arr, i, 0);
   }
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
   // int heap_arr[] = {4,17,3,12,9,6};
   // int n = sizeof(heap_arr)/sizeof(heap_arr[0]);

   int n;
   cout<<"Enter the array size: "<<endl;
   cin>>n;

   int heap_arr[n];
   int k;

   cout<<"Enter the integers one by one: "<<endl;

   for(int i=0; i<n; i++)
   {
      cin>>k;
      heap_arr[i] = k;
   }

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}