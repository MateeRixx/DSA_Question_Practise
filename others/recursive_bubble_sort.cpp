#include<bits/stdc++.h>
using namespace std;

//void correct index returning function 

int correct_index(vector<int> &arr , int low , int high)
{
    int i=low;
    int j=high;
    int pivot=arr[low];


    while(i<j)
    {
        //to keep equal elements to the left here we are doing <= 
        while(arr[i]<=pivot && i<=high)
        {
            i++;

        }

        //to avoid keeping dublicates to the right we are doing here only > 
        while(arr[j]>pivot && j>=low)
        {
            j--;

        }

        if(i<j)
        {
            swap(arr[i],arr[j]);

        }
    }

        swap(arr[low],arr[j]);
        return j;

}

void QuickSort(vector<int> &arr , int low , int high)
{
  if(low<high)
  {
    int Correct_index=correct_index(arr ,low , high);
    QuickSort(arr,low,Correct_index-1);
    QuickSort(arr,Correct_index+1,high);

  }
    
    

}


int main()
{

vector<int> arr={5,4,8,2,9,2,2,7};
QuickSort(arr,0,7);
for(int i=0;i<arr.size();i++)
{
    cout<<arr[i]<<"\t";
    
}
    return 0;

}