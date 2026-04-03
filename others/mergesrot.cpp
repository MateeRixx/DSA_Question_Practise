#include<bits/stdc++.h>
using namespace std;

//function to print array 

void print(vector<int> &arr , int low , int high)
{
    for(int i=low;i<high;i++)
    {
        cout<<arr[i]<<"\t";



    }
}
void merge_arrays(vector<int> &arr,int low , int mid , int high)
{
    int left=low;
    int right=mid+1;
    vector<int> temp;

    while(left<=mid && right<=high) // loop will only exexuite when both is true that is n/2
    {
        if(arr[left]<=arr[right])
        {
            temp.push_back(arr[left]);
            left++;

        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid) //n/2
    {
        temp.push_back(arr[left]);
            left++;
    }
    while(right<=high)  //n/2
    {
        temp.push_back(arr[right]);
            right++;
    }

    //loop to movie elements from temp to main arrat 
    for(int i=low;i<=high;i++) //n
    {
            arr[i]=temp[i-low];

    }

    
}
void merge_sort(vector<int>&arr , int low , int high)
{
    if(low>=high)
    {
        return ;

    }
    int mid=low+(high-low)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge_arrays(arr,low,mid,high);
   

   

    //fucntiont to print after sorting :
     



}


int main()
{

        vector<int> arr={3,5,2,21,2};

        int low=0;
        int high=arr.size()-1;
        
        merge_sort(arr,low,high);
        print(arr,low,high);
        
       


        


    return 0;

}