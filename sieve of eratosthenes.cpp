#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


void Black_box(int N)
{
    vector<int>prime(N+1,1);
    prime[0]=0;
    prime[1]=0;


    for(int i=2 ; i<=sqrt(N) ; i++)
    {
        if(prime[i]==1)
        {
            for(int j=i*i;j<=N;j=j+i)
            {
                prime[j]=0;

            }
        }
    }

    //printing 

    for(int i=2;i<=N;i++)
    {
        if(prime[i]==1)
        {
            cout<<i<<"\t";

        }
    }



}


int main()
{
    Black_box(30);


    return 0;

}
