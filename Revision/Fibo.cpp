#include<iostream>
using namespace std;


int fibonaci(int nth)
{
    if(nth<=0)
    {
        return 0;

    }

    if(nth==1)
    {
        return 1;

    }

   else{

    int ans= (fibonaci(nth-1)+fibonaci(nth-2));

    return ans;


   } 
}


int main()
{

    int number;
    cout<<"Enter a integer:";
    cin>>number;
    cout<<fibonaci(number);

    return 0;

}