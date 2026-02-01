#include<bits/stdc++.h>
using namespace std;





int main()
{

    int number;
    cout<<"give me a number:";
    cin>>number;
    

    int low=1;
    int high=number;
    int ans=1;


    while(low<=high)
    {
        int mid=low +(high-low)/2;

        if(mid*mid==number)
        {
           ans=mid;
           break;


        }
        else if(mid*mid<number){
            ans=mid;
              low=mid+1;

        }

        else{
            
          high=mid-1;
          


        }
    }


    cout<<ans;

   
    return 0;

}
