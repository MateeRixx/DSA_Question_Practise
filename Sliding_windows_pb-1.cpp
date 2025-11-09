#include<bits/stdc++.h>
using namespace std;

//fucntion jo ek range main sabki frequency store karega 

int  Frequency_tracker(string s,int l , int r )
{
    unordered_map<char,int>mpp;

    for(int i=l;i<=r;i++)
    {
        mpp[s[i]]+=1;

    }

    //lets take max frequncy within that range 

    int max_frq=0;
    for(auto elems:mpp)
    {
        if(elems.second>max_frq)
        {
            max_frq=elems.second;

        }
    }

    return max_frq;


}

//main driver code:

int characterReplacement(string s, int k)
{
    int l=0;
    int r=0;
    int max_freq=0;
    int length=0;


    while(r<s.size())
    {
        max_freq=Frequency_tracker(s,l,r);
        int window_length=r-l+1;
        int number_of_chars_to_c


        

        
    }
}


int main()
{



    return 0;

}
