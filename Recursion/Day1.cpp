#include<iostream>
#include<vector>
using namespace std;
//recusive function to print your name 5 time 
void   Print_Name(string yourname,int numberoftimes)
{
    if(numberoftimes<=0)
    {
        return ;

    }

    cout<<yourname<<endl;

    numberoftimes-- ;
    Print_Name(yourname,numberoftimes);




   

}

//fucntion for sum of n numbers using recusion
int sum_of_n(int numbers)
{
    
    if(numbers<=0)
    {
        return 0 ;

    }
    

    
   


    return (numbers+sum_of_n(numbers-1));
    
}

void  counting(int start,int end)
{
    
   if(start>end)
   {
    return ;

   }

   cout<<start<<endl;
   start++;
   counting(start,end);


}

//factorial 

long long factorial(long long number)
{
    if(number==0 || number==1 )
    {
        return 1;

    }

    return (number*factorial(number--));

}

 bool checkRecord(string s) {
       
       int P,A,L=0;

       for(int i=0;i<s.size();i++)
       {
        if(s[i]=='A')
        {
            A++;

        }

        else if(s[i]=='P')
        {
            P++;

        }
        else{
            L++;


        }
       }

       if(A<2 && L==0)
       {
        return true;

       }

       return false;
       



    }


    // reversing an array using recursion 

vector<int>revered(vector<int>&arr,int start , int end)
{
    if(start>end)
    {
       return arr;
       


    }

    swap(arr[start],arr[end]);
    start++;
    end--;
    revered(arr,start,end);

    return arr;


}


bool palindrome(string s)
{
    int i=0;

     if(s==" ")
     {
        return true;

     }


     if(s.size()==1)
     {
        return true;

     }

     bool ans=false;

     if(s[i]==s[s.size()-i-1])
     {
        ans=true;
        i++;
        palindrome(s);
        

     }

     if(ans==true)
     {
        return true;

     }

     return false;


}




int main()
{


   string s="1701";

    cout<<palindrome(s);







    return 0;


}