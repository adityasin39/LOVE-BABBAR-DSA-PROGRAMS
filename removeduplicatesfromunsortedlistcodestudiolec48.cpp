// // we have two approaches here one is the brute force which is O(n^2) and gives tle and the other is the map soln which does not give tle

// #include <bits/stdc++.h> 
// /****************************************************************
//     Following is the class structure of the Node class:
//     class Node
//     {
//     public:
//         int data;
//         Node *next;
//         Node(int data)
//         {
//             this->data = data;
//             this->next = NULL;
//         }
//     };
// *****************************************************************/
// //Approach 1 brute force O(n^2)
// Node *removeDuplicates(Node *head)
// {
//     if(head==NULL) return head;
//     Node* temp1=head;
//     while(temp1!=NULL  && temp1->next!=NULL )
//     {
//         Node* temp2=temp1;
//         while(temp2->next!=NULL)
//         {
//             if(temp1->data==temp2->next->data)
//             {
//                 Node* nodetodelete=temp2->next;
//                 temp2->next=temp2->next->next;
//                 delete(nodetodelete);
//             }
//             else
//             {
//                 temp2=temp2->next;
//             }
//         }
//         temp1=temp1->next;
//     }
//     return head;
// }
//Approach 2 map one tc=O(n) and sc=O(n)
#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
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
*****************************************************************/
// using a map tc=O(n) and sc=O(n)
Node *removeDuplicates(Node *head)
{
    if(head==NULL) return NULL;
    Node* temp=head;
   unordered_map<int,bool> m;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        if( temp!=NULL && m[temp->data] != true)
        {
      
        m[temp->data] = true;
        prev=temp;
        temp = temp->next;
        
      } 
      else{
      Node *nodetodelete = temp;

      prev->next =temp->next;
                  temp = temp->next;

      delete (nodetodelete);
      }
    }
    return head;
}