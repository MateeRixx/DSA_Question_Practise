#include<iostream>
using namespace std;


//defining class of our stack 


class Stack_Imp
{
    public:
    int TOP=-1;
    int Size=10;
    int st[10];


    //fucntion of our stack

    void push(int value_from_user)
    {
        if(TOP>Size)
        {
            cout<<"Stack overflow";

        }
        
        TOP++;
        st[TOP]=value_from_user;

    }

    int top()
    {
       
        
        return (st[TOP]);

    }


    //pop function 

    void pop()
    {
        if(TOP==-1)
        {
            cout<<"Stack underflow";

        }

        TOP=TOP-1;

    }

    int size()
    {
        return (TOP+1);

    }

};





int main()
{

    Stack_Imp st;
    st.push(10);
    st.push(5);
    st.push(3);
    st.push(88);

    while(st.size()!=0)
    {
        cout<<st.top()<<"\t";
        st.pop();

        

    }

    


    return 0;

}