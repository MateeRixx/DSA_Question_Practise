#include<bits/stdc++.h>
using namespace std;




    

void  rearrange(vector<int> &arr){

vector<int> temp_postive;
    vector<int> temp_negative;

    int p=0;
    int q=0;



    for(int i=0;i<arr.size();i++){
        if(arr[i]<0)
        {
           

            temp_negative.push_back(arr[i]);


        }
        else{
          

                temp_postive.push_back(arr[i]);


        }
    }

  



  
    //regarafing element back int main array 

    for(int i=0;i<arr.size();i++)
    {
        
        if(i%2==0 && p<temp_postive.size())

        {
            
            arr[i]=temp_postive[p++];
            

            

        }
        else if(q<temp_negative.size()){
            arr[i]=temp_negative[q++];
        }

        else if(p<temp_postive.size())
        {
            arr[i]=temp_postive[p++];
            
        }
    }

    

}

    int main()

    {


        vector<int> sample={-1,2,3,4,-3,1};

         rearrange(sample);

         for(int i=0;i<sample.size();i++)
         {
            cout<<sample[i]<<" ";

         }


    }