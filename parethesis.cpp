#include<bits/stdc++.h>
using namespace std;



int main()
{

    string test="(()())(())";
    int length=test.size();

  int depth=0;


    for(int i=0;i<length;i++)
    {
        if(test[i]=='(')
        {
            if(depth>0)
            {
                cout<<test[i];
                depth++;

            }
            
        }
       
        else{
            depth--;

           if(depth>0)
           {
            cout<<test[i];
            
           }

        }
    }

    



    
    

    return 0;

}