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
    vector<int> getRow;

    for(int C=1;C<=RowNumber;C++)
    {
        getRow.push_back(NCR(RowNumber-1,C-1));


    }

    return getRow;
    
}

void PascalTriangle(int N)
{
    
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
