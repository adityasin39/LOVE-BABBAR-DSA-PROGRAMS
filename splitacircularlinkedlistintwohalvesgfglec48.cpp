void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    if(head==NULL || head->next==NULL) return;
    Node* temp=head;
    int cnt=1;
    while(temp->next!=head)
    {
        temp=temp->next;
        cnt++;
    }
    temp->next=NULL;
    Node* slow=head;
    Node* fast=head;
    if(cnt%2!=0)
    {
        while(fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* n=slow;
        slow=slow->next;
        n->next=head;
        fast->next=slow;
        *head1_ref=head;
        *head2_ref=slow;
    
    }
    else
    {
        while(fast->next->next!=NULL)
        {
          slow=slow->next;
            fast=fast->next->next;   
        }
         Node* n=slow;
         slow=slow->next;
        n->next=head;
        fast->next->next=slow;
         *head1_ref=head;
        *head2_ref=slow;
    }
    
}