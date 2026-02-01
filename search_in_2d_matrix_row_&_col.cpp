#include<bits/stdc++.h>
using namespace std;

//function to search in an array 

bool search_in_array(vector<int>arr,int target)
{
   int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return true;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;


}


bool search_in_matrix(vector<vector<int>>&matrix, int target)
{
    int m=matrix.size();
    int n=matrix[0].size();
    


    int low=0;

    for(int i=0;i<m;i++)
    {
        if(search_in_array(matrix[i],target)==true)
        {
            return true;


        }
        
    }

    return false;

}





int main()
{

    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=60;


    cout<<search_in_matrix(matrix,target);


    return 0;

}
