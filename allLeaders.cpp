#include<bits/stdc++.h>
using namespace std;

vector<int> allLeader(vector<int>&arr)
{
    int n=arr.size();
    vector<int> temp;

   
    int maxi=arr[n-1];
    temp.push_back(maxi);
    


    for(int i=n-2;i>=0;i--)
    {
        if(arr[i]>=maxi)
        {
            temp.push_back(arr[i]);
            maxi=arr[i];


        }
    }

    //reverse beacuae we collected them in revese order :
    reverse(temp.begin(),temp.end());

    return temp;


}


int main()
{

    vector<int> sample={5,4,3,2,1};

   

     allLeader(sample);




    return 0;

}