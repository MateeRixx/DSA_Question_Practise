#include<iostream>
#include<vector>
using namespace std;

bool is_valid_min_heap(vector<int>&nums)
{
   int n=nums.size();

   for(int i=0;i<=(n-2)/2;i++)
   {
    int L=2*(i)+1;
    int R=2*(i)+2;

    if(L<n && nums[i]>nums[L]){
        return false;

    }

    if(R<n && nums[i]>nums[R]){
        return false;

    }
   }

   return true;


}

void Heapify(vector<int>&nums,int i){

    int n=nums.size();
    int largest=i;
    int L=(2*i) +1;
    int R=(2*i) +2;

    

    if(R<n && nums[R]>nums[largest])
    {
        largest=R;

    }
    if(L<n && nums[L]> nums[largest])
    {
        largest=L;

    }

    if(i!=largest)
    {
        swap(nums[i],nums[largest]);
        Heapify(nums,largest);

        
    }


}


vector<int> minToMaxHeap(vector<int>&nums) {

        //considering nums is just an array and we can make it a max heap 

        
        for(int i=nums.size()/2-1 ;i>=0 ;i-- )
        {
            Heapify(nums,i);

        }

        return nums;

    }

int main()
{

    vector<int>nums={2, 6, 3, 100, 120, 4, 5};
    vector<int>ans=minToMaxHeap(nums);
    for(auto elems:ans)
    {
        cout<<elems<<" ";

    }

    


    return 0;

}