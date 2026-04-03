#include<bits/stdc++.h>
using namespace std;

//funtion that will return largest element in our array 
int maximum(int arr[], int size)
{
    int max=arr[0];
    for(int i=0;i<size;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];

        }
    }

    return max;

}
int main()
{

    int size;
    cout<<"how many element you want :";
    cin>>size;

    int arr[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter your"<<i<<" th Number:";
        cin>>arr[i];

    }

    cout<<endl;
    for(int number:arr)
    {
        cout<<number<<"\t";

    }

    cout<<endl;
    
    int max=maximum(arr,size);
    cout<<"the max element in your arrays is :"<<max;


    return 0;
}