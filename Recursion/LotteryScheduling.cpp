#include<iostream>
#include<random>
#include<ctime>
using namespace std;


int main()
{

    srand(time(0));
    int A=0;
    int B=0;


    

    int trials;
    cout<<"how many trials you want to take:";
    cin>>trials;


    for(int i=0;i<trials;i++)
    {
        int randomNum = rand() % 101;
        if(randomNum>=0 && randomNum<=30)
        {
            cout<<"A choose:"<<randomNum<<endl;

            A++;

        }

         if(randomNum>=30 && randomNum<=100)
        {
             cout<<"B choose:"<<randomNum<<endl;
            B++;

        }

        
    }

    cout<<"A was picked:"<<A<<" time by CPU  where as B was picked "<<B<<" times";
    cout<<endl;


    



    return 0;

}