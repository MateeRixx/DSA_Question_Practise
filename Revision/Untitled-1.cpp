#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


//print function 

void print(vector<int>&nums)
{
    for(int i=0;i<nums.size();i++)
    {
        cout<<nums[i]<<"\t";

    }
}

void RemovedDublicates(vector<int>&nums)
{
    int i=0;
    int j=0;



    for(int j=0;j<nums.size();j++)
    {
        if(nums[j]!=nums[i]){
            //means we have a unique element 
            i++;
            nums[i]=nums[j];

        }
    }

    int endingindex=i+1;

    for(int m=0;m<endingindex;m++)
    {
        cout<<nums[m]<<"\t";

    }
    

}

// left roation of an array :

void leftRotate(vector<int>nums)
{
    int temp=nums[0];

    for(int i=1;i<nums.size();i++)
    {
        nums[i]=nums[i+1];

    }

    nums[nums.size()-1]=temp;

    print(nums);


}

void RightRotate(vector<int>nums)
{
    int temp=nums[nums.size()-1];

    for(int i=nums.size()-1;i>0;i--)
    {
        nums[i]=nums[i-1];

    }

    nums[0]=temp;

    print(nums);


}


int main()
{

    vector<int>nums={1, 1, 2, 2, 3, 4, 4};

   
    leftRotate(nums);

    cout<<endl;


    RightRotate(nums);



  


    return 0;

}