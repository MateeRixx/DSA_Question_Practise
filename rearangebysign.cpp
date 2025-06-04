#include<bits/stdc++.h>
using namespace std;

void sort_as_persign(vector<int>&arr)
{
    //loop for countaing positive and negative elements;
    int count_positive=0;
    int count_negative=0;

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

    count_negative=temp_negative.size();
    count_positive=temp_postive.size();




  
    //regarafing element back int main array 

    for(int i=0;i<arr.size();i++)
    {
        
        if(i%2==0)

        {
            
            arr[i]=temp_postive[p];
            p++;

            

        }
        else{
            arr[i]=temp_negative[q];
            q++;


        }
    }

  

    


    
}



int main()
{

    vector<int> sample={3,1,-2,-5,2,-4};

    sort_as_persign(sample);

    for(int i=0;i<sample.size();i++)
    {
        cout<<sample[i]<<" ";

    }

    return 0;

}