#include<bits/stdc++.h>
using namespace std;
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        //step-1

        if(hand.size()%groupSize!=0)
        {
            return false;

        }

        //need to count frequences 
        map<int,int>mp;
        for(auto cards:hand)
        {
            mp[cards]+=1;

        }

        while(!mp.empty())
        {
            int start = mp.begin()->first;

            for(int i=0;i<groupSize;i++)
            {
                int curr=start+i;

                if(mp.find(curr)==mp.end())
                {
                    return false;

                }
                mp[curr]--;
                if(mp[curr]==0)
            {
                mp.erase(curr);
                
            }
            }

            
        }

        return true;
        
    }
int main()
{


    return 0;
    
}