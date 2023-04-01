// we have two approaches here
// 1. counting frequencies of 0,1,2 and then replacing the data in the linked list
// 2. if data replacement is not allowed then we can use 3 dummy pointers which help us to merge the separate linked
// list of 0,1 and 2. can be done without dummy too but it becomes a bit complex. if you dont understand then refer to original love babbar video
/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/
// Approach 1
// Node* sortList(Node *head)
// {
//     Node* temp=head;
//     int zerocount=0;
//     int onecount=0;
//     int twocount=0;
//     while(temp!=NULL)
//     {
//         if(temp->data==0) zerocount+=1;
//         else if(temp->data==1) onecount+=1;
//         else twocount+=1;
//         temp=temp->next;
//     }
//     temp=head;
//     while(temp!=NULL)
//     {
//         while(zerocount--)
//         {
//             temp->data=0;
//             temp=temp->next;
//         }
//           while(onecount--)
//         {
//             temp->data=1;
//             temp=temp->next;
//         }
//           while(twocount--)
//         {
//             temp->data=2;
//             temp=temp->next;
//         }
//     }
//    return head;
// }
/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/
// Approach 2
void insertattail(Node* &tail,Node* &curr) // creating 3 separate lists
{
    tail->next=curr;
    tail=curr;
}
Node* sortList(Node *head)
{
    Node* zerohead= new Node(-1);// dummy node
    Node* onehead= new Node(-1);
    Node* twohead= new Node(-1);
    Node* zerotail=zerohead;
    Node* onetail=onehead;
    Node* twotail=twohead;
    Node* curr=head;
    while(curr!=NULL)
    {
        int val= curr->data;
        if(val==0)
        {
            insertattail(zerotail,curr);
        }
        else if(val==1)
        {
            insertattail(onetail,curr);
        }
        else insertattail(twotail,curr);
        curr=curr->next;
    }
    // merging
    if(onehead->next!=NULL) // what if there are no 1s
    {
        zerotail->next=onehead->next;
    }
    else{
        zerotail->next=twohead->next;
    }
    onetail->next=twohead->next;
    twotail->next=NULL;
    head=zerohead->next; // setting up head
    delete(zerohead); //deleting dummy
    delete(onehead);
    delete(twohead);
    return head;

}
