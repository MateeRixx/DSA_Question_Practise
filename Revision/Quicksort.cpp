#include<iostream>
#include<vector>
using namespace std;


int  partition(vector<int>&arr,int low , int high)
{
   int i=low;
   int j=high;
  int  pivot=arr[0];


  while(true)
  {
    do{
    i++;
   }while(arr[i]<pivot);

   do{
    j--;
    }while(arr[j]>pivot);

    if(i>j)
    {
        break;

    }

    swap(arr[i],arr[j]);

  }
   
  return i;


}


void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


int main(){

    vector<int>arr={5,3,8,4,2,7,1,10};
    quickSort(arr,0,arr.size());
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<"\t";

    }

    return 0;

}