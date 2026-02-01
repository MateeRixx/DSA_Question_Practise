#include<bits/stdc++.h>
using namespace std;


int count(vector<int>&greed,vector<int>&s)
{
    
    sort(greed.begin(),greed.end());
    sort(s.begin(),s.end());


        int l=0;
        int r=0;

        while(l<s.size()  &&  r<greed.size())
        {
            
            if(s[l]>=greed[r])
            {
                
                l++;
                r++;

            }
            else{
                l++;

            }
            
        }


   return r;


}


int main()
{

        vector<int>greed={1,3,3,4,5};
        vector<int>s={1,1,2,2,3,4};
    cout<<count(greed,s);



    return 0;

}