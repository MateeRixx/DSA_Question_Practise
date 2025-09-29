#include<bits/stdc++.h>
using namespace std;


int string_to_int(string number_from_user )
{
    int result=0;
    int sign=1;


   
        
    
    for(int i=0;i<number_from_user.size();i++)

    {

        
        

        if(number_from_user[i]=='-' )
        {
            sign=-1;

        }


        if(number_from_user[i]-'0'>=0 && number_from_user[i]-'0'<=9)
        {
            result=result*10+number_from_user[i]-'0';

        }

        if( number_from_user[i]<'0' || number_from_user[i]>'9' )
        {
            break;
        }
       
    }

    return (result*sign);
}


int main()
{

cout<<string_to_int("1337c0d3");



    return 0;

}