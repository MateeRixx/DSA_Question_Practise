#include<iostream>
#include<algorithm>
using namespace std;


//convert to binary

string binary(int n)
{
    string result;

    while(n>0)
    {
        if(n%2==1)
        {
            result+='1';

        }
        else{
            result+='0';

        }

        n=n/2;

    }

    // reverse(result.begin(),result.end());


    return result;

}


int number_of_bits_for_conversion(int a ,int b)
{
    string bin_1=binary(a);
    string bin_2=binary(b);
    int count=0;

    for(int i=0;i<max(bin_1.size(),bin_2.size());i++)
    {
        if(bin_1[i]!=bin_2[i])
        {
            count++;

        }
    }

    return count;

}

int main()
{

  int a=10;
  int b=7;

  cout<<(__builtin_popcount(a^b));



   
   
   
   
   
    return 0;



}