#include<iostream>
using namespace std;


double power(int x ,int n)
{
    double ans=1;

    long m=n;

    if(m<0)
    {
        m=m*-1;

    }

    while(m>0)
    {
        if(m%2==1)
        {
            ans=ans*x;
            m=m-1;

        }

        else{
            x=x*x;
            m=m/2;

        }


    }

    if(n<0)
    {
        ans=double(1.0)/double(ans);
    }

    return ans;

}
int main()
{

    cout<<power(3,5);
    


    return 0;

}