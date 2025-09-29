#include<bits/stdc++.h>
using namespace std;


//largest element in a row 

int largest_in_row(vector<int>row)
{
    int ans=*max_element(row);


    return ans;

}


vector<int> Peak_element(vector<vector<int>>&mat)
{
    int m=mat.size();
    int n=mat[0].size();
    vector<int>ans;


    //case of single element 

    if(m==1 && n==1)
    {
        ans={0,0};
        return ans;

    }

    for(int i=0;i<n;i++)
    {
        int temp=largest_in_row(mat[i]);
        
    }



}


int main()

{





    return 0;

}