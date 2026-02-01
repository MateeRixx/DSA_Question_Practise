#include<bits/stdc++.h>
using namespace std;



//pair of suffix and prefix counts 

int suffix_Y(string customer,int index=0)
{
    int Y=0;
    for(int i=index;i<=customer.size();i++)
    {
        if(customer[i]=='Y')
        {
            Y+=1;

        }
    }


    return Y;


}

//for prefix N 

int suffix_N(string customer,int index=0)
{
    int N=0;
    for(int i=index-1;i>=0;i--)
    {
        if(customer[i]=='N')
        {
            N+=1;

        }
    }


    return N;


}

 int bestClosingTime(string customer) {
        
        int minimum=INT_MAX;
        int besttime=0;

        for(int i=0;i<=customer.size();i++)
        {
            
            int penalty=suffix_N(customer,i)+suffix_Y(customer,i);

            if(penalty<minimum)
            {
                minimum=penalty;
                besttime=i;
            }
           


        }

        return besttime;

    }

int main()
{
    string cus="YYYY";
    
    // for(int i=0;i<=cus.size();i++)
    // {
    //     cout<<suffix_N(cus,i)<<'\t'<<suffix_Y(cus,i)<<"\t"<<suffix_N(cus,i)+suffix_Y(cus,i)<<endl;

    // }

    cout<<bestClosingTime(cus);

   


    return 0;

}