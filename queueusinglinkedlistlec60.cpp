// tc=o(1)
#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
   int data;
   Node* next;
   Node(int data)
   {
    this->data=data;
    next=NULL;
   }
};
class Queue
{
     Node* qfront;
     Node* rear;
  public:
    Queue()
    {
         qfront=NULL;
         rear=NULL;
    }
    void enqueue(int data)
    {
       Node* newnode= new Node(data);
       if(!newnode)
       {
        cout<<"Queue is full"<<endl;
        return;
       }
       if(!rear)
       {
        qfront=newnode;
        rear=newnode;
        return;
       }
       rear->next=newnode;
       rear=newnode;
    }
    int dequeue()
    {
        if(qfront==NULL) return -1;
        int ans=qfront->data;
        Node* temp=qfront;
        qfront=qfront->next;
        temp->next=NULL;
        if(qfront==NULL) rear=NULL;
        delete(temp);
        return ans;

    }
    bool isEmpty()
    {
        if(qfront==NULL) return true;
        else return false;
    }
    void display()
    {
        Node* temp=qfront;
       while(temp!=NULL)
       {
        cout<<temp->data<<" ";
        temp=temp->next;
       }
    }
    int  front()
    {
       if(qfront==NULL) return -1;
       else return qfront->data;
    }
    int back()
    {
      if(qfront==NULL) return -1;
      else return rear->data;
    }
};
int main(){
      Queue q;
      q.enqueue(1);
      q.enqueue(2);
      q.enqueue(3);
      q.enqueue(4);
      q.enqueue(5);
      cout<<q.front()<<endl;
      cout<<q.back()<<endl;
      q.display();
      cout<<endl;
      cout<<q.dequeue()<<endl;
       cout<<q.front()<<endl;
      cout<<q.back()<<endl;
      q.display();
      cout<<endl;
      cout<<q.dequeue()<<endl;
       cout<<q.front()<<endl;
      cout<<q.back()<<endl;
      q.display();
      cout<<endl;
      cout<<q.dequeue()<<endl;
       q.display();
      cout<<endl;
      cout<<q.dequeue()<<endl;
       q.display();
      cout<<endl;
      cout<<q.dequeue()<<endl; 
       q.display();
      cout<<endl;
      cout<<q.isEmpty()<<endl;
      cout<<q.front()<<endl;
      cout<<q.back()<<endl;


    return 0;
}