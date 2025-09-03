#include<bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>>&matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();
    
    for(int i=0;i<m;i++)
    {
        cout<<"[";
        for(int j=0;j<n;j++)
        {
            cout<<matrix[i][j]<<" ";

        }

        cout<<"]";
        
    }
}

void Tranpose(vector<vector<int>>&matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();


    for(int i=0;i<m-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(i==j)
            {

            }

            else{
                swap(matrix[i][j],matrix[j][i]);

            }
        }
    }

    //reverse every row

    for(int i=0;i<n-1;i++)
    {
        reverse(matrix[i].begin(),matrix[i].end());
        
    }

    
}


int main()
{
    vector<vector<int>> sample={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
   

    Tranpose(sample);

    printMatrix(sample);



    return 0;

}