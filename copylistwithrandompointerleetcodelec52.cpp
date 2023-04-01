// here we have two approaches
// 1. is the map one. As we want to clone a list which has a random pointer too so this cant be done without any sort of mapping so we use a map here. TC=O(n) and SC=O(n)
// 2. here we dont use a map instead we link the two lists which sort of creates a virtual map and so we save the extra hashing space. TC=O(n) and SC=O(1) ->> best approach
// if you dont understand then refer to https://www.youtube.com/watch?v=VNf6VynfpdM
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// Approach 1
// direct map se clone list nahi banta 
// creating clone list without random pointers
// void insertattail(Node* & tail, Node* temp)
// {
//          tail->next=temp;
//          tail=temp;
// }
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         Node* dummy= new Node(-1);
//         Node* dummytail=dummy;
//         Node* temp1=head;
//         while(temp1!=NULL)
//         {
//             Node* clone= new Node(temp1->val);
//             insertattail(dummytail,clone);
//             temp1=temp1->next;
//         }
//         temp1=dummy->next;
//         dummy->next=NULL;
//         delete(dummy);
//         unordered_map<Node*, Node*> m;
//         Node* temp=head;
//         while(temp!=NULL)
//         {
//             m[temp]=temp1; // mapping is done here
//             temp=temp->next;
//             temp1=temp1->next;
//         }
//         Node* curr=head;
//         temp=m[head];
//         // making random connection
//         while(temp!=NULL)
//         {
//             if(curr->random==NULL) temp->random=NULL;
//             else
//             {
//             temp->random=m[curr->random];
//             }
//             temp=temp->next;
//             curr=curr->next;
//         }
//         return m[head];
//     }
// };
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// Approach 2
// creating a clone list
    void insertattail(Node* & tail, Node* temp)
{
         tail->next=temp;
         tail=temp;
}
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
           Node* dummy= new Node(-1);
        Node* dummytail=dummy;
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* clone= new Node(temp->val);
            insertattail(dummytail,clone);
            temp=temp->next;
        }
        Node* clonehead=dummy->next;
        dummy->next=NULL;
        delete(dummy);
        Node* temp1=head;
        Node* temp2=clonehead;
        Node* front1=temp1->next;
        Node* front2=temp2->next;
        // adding the clone list nodes in between the original list
        while(temp1!=NULL)
        {
            temp1->next=temp2;
            temp2->next=front1;
            temp1=front1;
            temp2=front2;
            if(front1!=NULL)
            front1=front1->next;
            if(front2!=NULL)
            front2=front2->next;
        }
        Node* curr=head;
        // making random connection
        while(curr!=NULL)
        {
            if(curr->random==NULL)
            {
                curr->next->random=NULL;
            }
            else
            {
                curr->next->random=curr->random->next;
            }
            curr=curr->next->next;
        }
        // breaking the links between original and cloned list
        Node* a=head;
        Node* b=clonehead;
        while(a!=NULL)
        {
            a->next=b->next;
            if(b->next==NULL) break;
            b->next=b->next->next;
            a=a->next;
            b=b->next;
        }
        return clonehead;
    }
};