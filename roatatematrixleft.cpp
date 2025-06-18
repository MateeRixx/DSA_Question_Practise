#include<bits/stdc++.h>
using namespace std;

void PrintMatrix(vector<vector<int>>&matrix){
     int m=matrix.size();
    int n=matrix[0].size();
    
    for(int i=0;i<m;i++)
   {
    for(int j=0;j<n;j++)
    {
        cout<<matrix[i][j]<<" ";

    }

    cout<<endl;

   }
}

void rotateMatrix(vector<vector<int>> &matrix)
{
    int m=matrix.size();
    int n=matrix[0].size();

    vector<vector<int>> roated_matrix(n,vector<int>(m));
    int row_no=m;
    int col_no=n;


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            roated_matrix[j][m-1-i]=matrix[i][j];
            row_no--;


        }

        
    }

      for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j]=roated_matrix[i][j];


        }

        
    }




    

     

  

}


int main()
{

    vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};

    rotateMatrix(matrix);
    PrintMatrix(matrix);
    

   

    return 0;

}
