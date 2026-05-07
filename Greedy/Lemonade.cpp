#include <bits/stdc++.h>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
       
    
    map<int, int> mpp;
    for (auto bill : bills)
    {
        if (bill == 5)
        {
            mpp[bill]++;
        }

        else if (bill == 10)
        {
            if(mpp[5]<0)
            {
                return false;
            }
            mpp[bill]++;
            mpp[5]--;
        }

        else 
        {
            
            mpp[bill]++;
            if(mpp[10]<=0)
            {
                while(bill!=5)
                {
                    mpp[5]--;

                    bill=bill-5;
                    
                }
            }
            
            else{
                mpp[10]--;
            mpp[5]--;
            }
            
            

        }
    }

    // checking mapp after traverls 

    for(auto pairs :mpp)
    {
        cout<<pairs.first<<"\t"<<pairs.second<<endl;

    }

    return true;
        
    }

int main()
{

    vector<int>bills={5,5,5,20,10,10};
    cout<<lemonadeChange(bills);




    return 0;
}