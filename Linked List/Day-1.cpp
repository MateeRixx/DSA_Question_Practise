#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;


    //constuctor

    Node(int data )
    {
        this->data=data;
        this->next=NULL;

    }

};

Class Linkedlist{
   
    Node *head;

    public:

    Linkedlist()
    {
        head=NULL;

    }

     void insertAtHead(int data) {

  
        Node *newNode = new Node(data);

     
        if (head == NULL) {
            head = newNode;
            return;
        }

   
        newNode->next = this->head;
        this->head = newNode;
    }


    Node*removeEL(Node*head , int element)
    {
        //check if head is the element or not 

        //basecase 1
        
        if(head==NULL)
        {
            return head;


         }
           
        if(head->data=element)
            {
                Node*temp=head;
                head=head->next;
                delete(temp);
                return head;


            }

        Node* temp=head;
        Node*prev=NULL;

        while(temp!=NULL)
        {
            if(temp->data=element)
            {
                prev->next=prev->next->next;
                temp=temp->next;

            }
        }
        
       prev=temp;
       temp=temp->next;

    }

    return head;
}


int main()
{



    return 0;

}