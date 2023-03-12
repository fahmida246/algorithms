#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *next;

};
// head = tail->next
Node *temp,*tail=0, *head=0,*prevnode,*nextnode,*current,*nextitem,*p,*q,*r,*temp1;
int b[100];
void insertatfirst(int x)
{
    Node *newnode = new Node();
    newnode->data=x;

    if(tail==0)
    {
        tail= newnode;
        tail->next = newnode;
    }
    else
    {
       newnode->next = tail->next;
       tail->next = newnode;
    }
}
void insertatlast(int x)
{
     Node *newnode = new Node();
    newnode->data=x;

    if(tail==0)
    {
        tail= newnode;
        tail->next = newnode;
    }
    else
    {
       newnode->next = tail->next;
       tail->next = newnode;
       tail = newnode;
    }
}
void insertatpos(int pos,int x)
{
    int i=0;
    Node *newnode = new Node();
    newnode->data=x;
    temp=tail->next;

    if(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;

}
void deleteatfirst()
{
    temp = tail->next;
    if(tail ==0){
        cout<<"no node";
    }
    else if (temp==temp->next){

        delete temp;
        tail = 0;
    }
    else
     {
         tail->next = temp->next;

        delete temp;
    }
}
void deleteatpos(int pos)
{
    int i=0;
    current=tail->next;
    if (i<pos-1)
    {
        current=current->next;
        i++;
    }
    nextnode=current->next; // deketed node
    current->next= nextnode->next;
    delete nextnode;
}
void deleteatlast() // same as linked list
{
     temp = tail->next;
     do{
            prevnode = temp;
            temp = temp->next;

     }while(temp->next!= tail->next);
     prevnode->next = tail->next;
     delete temp;
     tail = prevnode;

    }

void counti()
{   int countoflist=0;
    temp= tail->next;
    do
    {
        countoflist++;
        temp=temp->next;
    }while(temp!=tail->next);
    cout<<"count is-> "<<countoflist<<endl;
}

void display()
{
    temp= tail->next;
    do
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }while(temp!=tail->next);
}
int main()
{
    insertatfirst(4);
    insertatfirst(4);
    insertatfirst(9);
    insertatlast(99);
    insertatlast(79);
    insertatlast(79);
    insertatpos(2,50);
    cout<<"insertion display"<<endl;
    display();
cout<<"delete at first"<<endl;
     deleteatfirst();
     display();

    deleteatlast();
    cout<<"after deleting"<<endl;
   display();
      cout<<"final deletion"<<endl;
     deleteatpos(2);
     display();
     counti();

/**
     counti();
     sumofdata();
     minimum();
     searchi(50);
     sorti();
     display();
    int    b=isSorted();
     cout<<"sorted or not "<<b<<endl;

    //int    w=isLoop(); cout<<"there is loop or not "<<w<<endl;
     removeDuplicatefromsorted();
     removeDuplicate();
     display();
    // reverseusingArray();
    cout<<"reverse";
    reverselist();
     display();
**/
}

