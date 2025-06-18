#include<bits/stdc++.h>
using namespace std;

int appearsNby2(vector<int>&nums){
    int N=nums.size();
    int maxi=*max_element(nums.begin(),nums.end());
  

    map<int,int> mymap;


    for(int i=0;i<N;i++)
    {
        mymap[nums[i]]+=1;


    }


   for(auto&p:mymap)
   {
    if(p.second>N/2)
    {
        return p.first;
        
    }
   }


    return -1;



}


int main(){

vector<int> sample;
int size;
cout<<"Enter size;";
cin>>size;
sample.resize(size);

for(int i=0;i<size;i++)
{
    
    cout<<"Enter your number:";
    cin>>sample[i];
  

}

cout<<appearsNby2(sample);



return 0;

}