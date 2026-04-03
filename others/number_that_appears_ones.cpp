#include<bits/stdc++.h>
using namespace std;

 int singleNumber(vector<int>& nums) {

    int result=0;
    
 
    for(int num : nums) {
        result ^= num;
    }
    return result;
}


 


int main()
{
    vector<int> sample={1};

    cout<<singleNumber(sample);



    return 0;

}