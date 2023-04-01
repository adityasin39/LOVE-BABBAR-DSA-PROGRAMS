#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int data)
{
    this->data=data;
    next=NULL;
    prev=NULL;
}
};
void insertAtHead(Node *&head,Node* &tail, int d)
{
    if(head==NULL)  // if initially linked list is empty
    {
    Node * temp= new Node(d);
    head=temp;
    tail=temp;
    }
    else{
    Node * temp= new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
    
}
void print(Node *head)
{
    Node * temp=head;
    while(temp!=NULL) // temp and temp->next are different
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
      cout<<endl;
}
  Node* reverselist(Node *head)
     {
            if((head==NULL) || (head->next==NULL)) return head;
       Node* temp=reverselist(head->next);
        head->next->next=head;
        head->prev=head->next;
        head->next=NULL;
        return temp;
     }

int main(){
    Node *head=NULL;
    Node *tail=NULL;
    insertAtHead(head,tail,1);
    insertAtHead(head,tail,2);
    insertAtHead(head,tail,3);
    insertAtHead(head,tail,4);
    insertAtHead(head,tail,5);
    print(head);
    Node* newhead=reverselist(head);
    print(newhead);


    return 0;
}