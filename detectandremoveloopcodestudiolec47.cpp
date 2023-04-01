/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/
Node *removeLoop(Node *head)
{
    if(head==NULL) return NULL;
    if(head->next==NULL) return head;
    Node* slow=head;
    Node* fast=head;
    Node* entry=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            while(entry!=slow)
            {
                entry=entry->next;
                slow=slow->next;
            }
                        break;

        }
    }
    if(fast==NULL || fast->next==NULL) return head;
    // removing loop
    Node* temp=slow;
    while(temp->next!=slow)
    {
        temp=temp->next;
    }
    temp->next=NULL;
    return head;


}