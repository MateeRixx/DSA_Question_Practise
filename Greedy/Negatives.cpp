#include<bits/stdc++.h>
using namespace std;

int counter(vector<int>arr)
{
    int firstNegative=-1;
    int l=0;
    int h=arr.size()-1;
    while(l<h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]<0)
        {
            firstNegative=mid;
            h=mid-1;
          
           
            

        }

        else{
            l=mid+1;

        }
    }

    return arr.size()-firstNegative;
}




int main()
{
    vector<int>arr={4,3,2,-1};
    cout<<counter(arr);

    return 0;

}