/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/
void insertattail(node* &tail,node* temp)
{
          tail->next=temp;
          tail=temp;
}
node* merge(node* left, node* right)
{
    node* dummy=new node(-1);
    node* dummytail=dummy;
    node* temp1=left;
    node* temp2=right;
    while(temp1!=NULL && temp2!=NULL)
    {
        if((temp1->data)<(temp2->data))
        {
            node* c=temp1->next;
            temp1->next=NULL;
              insertattail(dummytail,temp1);
                      temp1=c;

        }
        else
        {
           node* n=temp2->next;
            temp2->next=NULL;
            insertattail(dummytail,temp2);
                    temp2=n;

        }
    }

    if(temp1!=NULL)
    {
        dummytail->next=temp1;
        
    }
    if (temp2 != NULL) {
      dummytail->next = temp2;
    }
    node *head = dummy->next;
    dummy->next = NULL; 
                        
    delete (dummy);

    return head;
}

node* getmid(node* head)
{
    node* slow=head;
    node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}
node* mergeSort(node *head) {
    // base case
   if(head->next==NULL) return head;
   node* mid=getmid(head);
   node* left=head;
   node* right=mid->next;
   mid->next=NULL;
   left=mergeSort(left);
   right=mergeSort(right);
   node* ans=merge(left,right);
   return ans;
}
