#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class ListNode
{
    public:
    int data;
    ListNode * next=NULL;

    //constuttor

    ListNode(int data , ListNode* next)
    {
       
        this->data=data;
        this->next=next;

    }

};

//function to add in front 



//function that will take our string and make linkedlist ot of it 

ListNode *str_to_ll(string summation )

{

    if(summation.empty())
    {
        return NULL:

    }
    int sizeofLL=summation.size();

    ListNode* newHead = new ListNode(summation[0] - '0', nullptr);
    ListNode* current = newHead;

    //make a new node from first elements 

    ListNode * newHead=new ListNode(summation[0],nullptr);

    for(int i=1;i<sizeofLL;i++)
    {
      current->next = new ListNode(summation[i] - '0', nullptr);
        current = current->next;
    }

     return newHead;
    }

   



//fucntion that will take input from string and make a linkedlist outof it 
int main()
{
    string number_1="246";
    string number_2="387";

    reverse(number_1.begin(),number_1.end());
    reverse(number_2.begin(),number_2.end());

    int addition=stoi(number_1)+stoi(number_2);
    string new_str=to_string(addition);
    reverse(new_str.begin(),new_str.end());

    str_to_ll(new_str);

    



   






    return 0;

}