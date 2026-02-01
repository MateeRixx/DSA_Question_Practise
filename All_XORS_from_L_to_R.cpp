#include<iostream>
using namespace std;

//function that takes an array and return integer for all the xor 

int allXors(int L, int R)
{
    int ans=0;
    for(int i=L ; i<=R ; i++)
    {
        ans=ans^i;


    
    }

    return ans;


    
}


int main()
{

    cout<<allXors(3,5);


    return 0;

}
