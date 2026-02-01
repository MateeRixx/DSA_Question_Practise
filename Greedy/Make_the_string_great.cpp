#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string good_string(string s)
{

    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        char curr = s[i];
       
        if(!st.empty())
        {
            char prev=st.top();
            if (abs(int(prev) - int(curr)) == 32)
            {
                st.pop();
                continue;

            }

        }

        st.push(curr);

    }
        
            
            

    // checking if stack is empty
    string ans;
    while (!st.empty())
    {
            ans.push_back(st.top());
            st.pop();
    }

    reverse(ans.begin(), ans.end());
    
   return ans;
}

int main()
{

    string s = "leEeetcode";
    cout<<good_string(s);

   



}


