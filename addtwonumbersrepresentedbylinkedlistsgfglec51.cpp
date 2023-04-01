// TC =O(m+n) and sc= O(max(m,n))
// in this approach we reverse both the lists to add and then check for sum and carry and add nodes accordingly
// if you dont understand then refer to original love babbar video
struct Node* reverse( struct Node* head)
 {
      struct Node* prev=NULL;
       struct Node* curr=head;
       while(curr!=NULL)
       {
            struct Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
       }
     return prev;
 }
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
       struct Node* head1= reverse(first);
       struct Node* head2= reverse(second);
        struct Node* temp1=head1;
         struct Node* temp2=head2;
          struct Node* dummy= new  struct Node(-1);
           struct Node* dummytail=dummy;
          int carry=0;
         while(temp1!=NULL || temp2!=NULL|| carry!=0)
         {
             int val1=0;
             if(temp1!=NULL) val1=temp1->data;
             int val2=0;
             if(temp2!=NULL) val2=temp2->data;
            
             int sum=carry+val1+val2;
             int digit=sum%10;
             carry=sum/10;
              struct Node* temp= new  struct Node(digit);
              dummytail->next=temp;
              dummytail=temp;
              if(temp1!=NULL) temp1=temp1->next;
              if(temp2!=NULL) temp2=temp2->next;
         }
      
         struct Node* head=dummy->next;
         dummy->next=NULL;
         delete(dummy);
         struct Node* finalhead=reverse(head); // reverse to get the final answer
         return finalhead;
         
    }
};