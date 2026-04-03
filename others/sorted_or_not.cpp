#include<bits/stdc++.h>
using namespace std;

bool sorted_or_not(int arr[],int size){

    if(size==1)
    {
        return true ;

    }
    else{

        for(int i=0;i<size;i++)
    {
        
        if(arr[i]>arr[i+1])
        {
            return true ;

        }

        

        }
    }
    return true;

    }



int main()
{

    int arr[5]={1,1,1,1,1};
    int arr_2[1]={1};
    int arr_3[6]={2,4,6,8,10,12};
    int arr_4[4]={9,3,7,6};

    cout<<sorted_or_not(arr,5)<<endl;
    cout<<sorted_or_not(arr_2,1)<<endl;
    cout<<sorted_or_not(arr_3,6)<<endl;
    cout<<sorted_or_not(arr_4,4)<<endl;

    

    return 0;

}