#include<bits/stdc++.h>
using namespace std;

int nth_root(int n , int m )
{
    int low=1;
    int high=m;

    int ans=-1;

    while(low<=high)
    {
        int mid=low+(high-low)/2;
        long long  value=1;



        for(int i=1;i<=n;i++){
            value=value*mid;
            if(value>m){
                break;
            }
        }

        if(value==m)
        {
            return mid;

        }
        else if(value<m)
        {
            ans=mid;
            low=mid+1;
        }

        else{
            high=mid-1;

        }
        
            

        
    }

    return -1;

}


int main()
{

    int number;
    int root;

    while(true){

    cout<<"enter a number:";
    cin>>number;

    cout<<"Enter root value:";
    cin>>root;

    cout<<"the "<<root<<" of "<<number<<" is"<<nth_root(root,number)<<endl;

    }

    



    return 0;

}
