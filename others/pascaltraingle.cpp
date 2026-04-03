#include<bits/stdc++.h>
using namespace std;

int NCR(int N , int R)
{
    int res=1;
    for(int i=0;i<R;i++)
    {
        res=res*(N-i);
        res=res/(i+1);

    }

    return res;

}

void Row_of_pascal(int RowNumber)
{
    
    for(int C=1;C<=RowNumber;C++)
    {
        cout<<" "<<NCR(RowNumber-1, C-1)<<" ";

    }
}

void PascalTriangle(int N)
{
   vector<vector<int>> Triangle;

   for(int i=1;i<N;i++)
   {
    vector<int>row;
    for(int j=0;j<=i;j++ )
    {
        row.push_back(NCR(i,j));

    }

    Triangle.push_back(row);


   }

    for (const auto& row : Triangle)
    {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }

   

}
int main()
{

    int Row;
    cout<<"Enter row number:";
    cin>>Row;

    int Column;
    cout<<"Enter Column Number:";
    cin>>Column;

    cout<<"Element at given postion is :"<<NCR(Row-1, Column-1);

    cout<<endl;

    Row_of_pascal(Row);
    cout<<endl;

    PascalTriangle(Row);




    return 0;

}