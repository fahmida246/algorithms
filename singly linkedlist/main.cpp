#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *temp, *head=0,*prevnode,*nextnode,*current,*nextitem,*p,*q,*r;
int b[100];
void insertatfirst(int x)
{
    Node *newnode = new Node();
    newnode->data=x;
    newnode->next= head;
    head=newnode;
}

void insertatlast(int x)
{
    Node *newnode = new Node();
    newnode ->data=x;
    temp=head;
    while(temp->next!=0)
    {
        temp= temp->next;
    }
    temp->next= newnode;
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
    newnode->next = temp->next;
    temp->next= newnode;


}
void deleteatfirst()
{
    temp=head;
    head= temp->next;
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
    nextnode=temp->next;
    temp->next= nextnode->next;
    delete nextnode;
// eta hocche temp node ta current node dekhae so temp next ja ta delete korte hobe,
//akhon new node temp->next hobe and oitar next er value newnode next


}
void deleteatlast()
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
void display()
{
    temp= head;
    while(temp!=0)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
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
            delete q;
            q= p->next;
        }
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

void reverseusingArray(){
    temp=head;
    int i=0;
    while(temp!=0){
        b[i] = temp->data;
        i++;
        temp=temp->next;
        //i++;
    }
    i--; // i ke akebe last index e anar jonno
    temp=head; // temp k abar shuru theke assign korte hobe
    while(temp!=0){
        temp->data = b[i];
        i--;
        temp=temp->next;
    }

}
void reverselist(){
    p = head;
    q=0;
    r=0;
    while(p!=0){
        r= q;
        q= p;
        p= p->next;
        q->next = r;
    }
    head=q;
}
int isLoop()
{
    p=q=temp;
       while(p!=0 && q!=0){
        p = p->next;
        q= q->next->next;
       // q = q->next;
    }
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }
}


    /**
    while(p && q){
        p = p->next;
        q= q->next;
        q = q->next;
    }
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }
    **/

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
   // deleteatfirst();
   //deleteatlast();
  // cout<<"after deleting"<<endl;
   // display();
  //  cout<<"final deletion"<<endl;
  //  deleteatpos(2);
   // display();
    counti();
    sumofdata();
    minimum();
    searchi(50);
    sorti();
    display();
int    b=isSorted();
    cout<<"sorted or not "<<b<<endl;
int    w=isLoop(); cout<<"there is loop or not "<<w<<endl;
    //removeDuplicatefromsorted();
    removeDuplicate();
   // reverseusingArray();
   reverselist();
    display();

}
