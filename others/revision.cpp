#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int size)
{
  for(int i=0;i<size;i++)
  {
    int j=i;
    while(j>0 && arr[j-1]>arr[j])
    {
      swap(arr[j-1],arr[j]);
      j--;


    }
  }

  for(int i=0;i<5;i++)
{
  cout<<arr[i]<<"\t";

}

}

int main()
{

  int arr[5]={1,2,6,4,5};
 
  
  insertion_sort(arr,5);




  return 0;

}