#include<bits/stdc++.h>
using namespace std;

int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        //part of code to get total of apples 

        int total_apples=0;
        for(auto apples:apple)
        {
            total_apples=total_apples+apples;

        }

        sort(capacity.begin(),capacity.end());

        int count=0;
        int i=capacity.size()-1;
        while(total_apples>0)
        {
            
            total_apples=total_apples-capacity[i];
            count++;
            i--;

        }

        return count;

    }



int main()
{
    vector<int>apple={1,3,2};
    vector<int>capacity={4,3,1,5,2};

    cout<<minimumBoxes(apple,capacity);


    return 0;

}