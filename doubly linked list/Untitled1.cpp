#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *prev;
    Node *next;

};
Node *temp,*tail, *head=0,*prevnode,*nextnode,*current,*nextitem,*p,*q,*r,*temp1;
int b[100];
void insertatfirst(int x)
{
    Node *newnode = new Node();
    newnode->data=x;

    if(head==0)
    {
        head=tail= newnode; // tail last take point korbe
    }
    else
    {
        head->prev = newnode; // extra for doubly
        newnode->next = head;
        head= newnode;
    }
}
void insertatlast(int x)
{
    Node *newnode = new Node();
    newnode ->data=x;
    //temp=head;
    //  while(temp->next!=0)
    //  {
    //      temp= temp->next;
    //  }
    tail->next= newnode;
    newnode->prev = tail;
    tail = newnode;
    newnode->next=0;
}
void insertatpos(int pos,int x)
{
    int i=0;
    Node *newnode = new Node();
    newnode->data=x;
    temp=head;

    if(i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    temp->next->prev = newnode;
    newnode->next = temp->next;
    newnode->prev = temp;
    temp->next = newnode;

}
void deleteatfirst()
{
    temp=head;
    head= head->next;
    head->prev =0; // new added line
    delete temp;
}
void deleteatpos(int pos)
{
    int i=0;
    temp=head;
    if (i<pos-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode=temp->next; // deketed node
    temp->next= nextnode->next;
    nextnode->next->prev= temp->next; // new added line
    delete nextnode;
}
void deleteatlast() // same as linked list
{
    temp=head;
    while(temp->next!=0)
    {
        prevnode= temp;
        temp=temp->next;
    }
    prevnode->next =0;
    delete temp;
}
void counti()
{   int countoflist=0;
    temp= head;
    while(temp!=0)
    {
        countoflist++;
        temp=temp->next;
    }
    cout<<"count is-> "<<countoflist<<endl;
}
void sumofdata(){
    temp=head;
    int sum=0;
    while(temp!=0){
        sum = sum+temp->data;
        temp = temp->next;
    }
    cout<<"sum is-> "<<sum<<endl;
}
void minimum(){
    temp=head;
    int mini = 100;
    while(temp!=0){
        if(temp->data<mini){
            mini = temp->data;
        }
        temp= temp->next;
    }
cout<<"minimum is-> "<<mini<<endl;
}
void searchi(int x){
    temp=head;
    int countx=0;
    while(temp!=0){

        if(temp->data==x){
            cout<<"data found at "<<countx<<" index "<<endl;
        }
        temp=temp->next;
        countx++;
    }

}
int isSorted(){
    temp=head;
    int x = -1000;
    while(temp!=0){
            if(temp->data<x){ // ager value ta boro hole return false
                return 0; // 0 -> false
            }
            x= temp-> data;
            temp= temp->next;

    }
    return 1; //true
}
void reverselist()
{
    p = head;
    while(p!=0)
    {
        swap(p->prev,p->next);

        p= p->prev;  // traverse

        if(p!=NULL && p->next==NULL)
        {
           head=p;
        }
    }
}
void sorti()
{   int temp1;
    current=head;
    while(current!=0) // start from head to last
    {
        nextitem = current->next;
        while(nextitem!=0) // start from next value of head
        {
            if(current->data>nextitem->data) // compare head(current) er data and > head->next(next item) er data
            {
                //swap(current->data,nextitem->data);
                temp1= current->data;
                current->data = nextitem->data;
                nextitem->data = temp1;
            }
            nextitem= nextitem->next; //
        }
        current = current->next;
    }
}
void removeDuplicate()
{
    p = head;
    while(p!=0)
    {
        q = p->next;
        while(q!=0)
        {
            if(p->data == q->data)
            {
                p->next = q->next;
                q->next->prev = p;
                delete q;
                q = p->next;

            }
            else
            {
                q=q->next;
            }
        }
        p=p->next;
    }
}
void removeDuplicatefromsorted()
{
    p = head;
    q  = head->next;
    while(q!=0)
    {
        if(p->data!= q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next= q->next;
            q->next->prev = p;
            delete q;
            q= p->next;
        }
    }
}


void display()
{
    temp= head;
    while(temp!=0)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
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
    /**
     deleteatfirst();
    deleteatlast();
    cout<<"after deleting"<<endl;
    display();
      cout<<"final deletion"<<endl;
     deleteatpos(2);
     display();
     **/

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

}
