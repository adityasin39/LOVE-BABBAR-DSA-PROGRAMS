// // here we have three approaches 
// // 1. is the standard merge which is same as merging two sorted arrays
// // 2. is the recursive approach of 1
// // 3. is the orginal love babbar approach which is the best in time and space
// #include <bits/stdc++.h> 
// #include <bits/stdc++.h> 
// /************************************************************

//     Following is the linked list node structure.
    
//     template <typename T>
//     class Node {
//         public:
//         T data;
//         Node* next;

//         Node(T data) {
//             next = NULL;
//             this->data = data;
//         }

//         ~Node() {
//             if (next != NULL) {
//                 delete next;
//             }
//         }
//     };

// ************************************************************/
// //Approach 1
// // using dummy node
// void insertattail(Node<int>* &tail,Node<int>* temp)
// {
//           tail->next=temp;
//           tail=temp;
// }
// Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
// {
//     Node<int>* dummy=new Node<int>(-1);
//     Node<int>* dummytail=dummy;
//     Node<int>* temp1=first;
//     Node<int>* temp2=second;
//     while(temp1!=NULL && temp2!=NULL)
//     {
//         if((temp1->data)<(temp2->data))
//         {
//             Node<int>* c=temp1->next;
//             temp1->next=NULL;
//               insertattail(dummytail,temp1);
//                       temp1=c;

//         }
//         else
//         {
//             Node<int>* n=temp2->next;
//             temp2->next=NULL;
//             insertattail(dummytail,temp2);
//                     temp2=n;

//         }
//     }

//     if(temp1!=NULL)
//     {
//         dummytail->next=temp1;
        
//     }
//     if(temp2!=NULL)
//     {
//         dummytail->next=temp2;
    
//     }
//     Node<int>* head=dummy->next;
//     dummy->next=NULL; // before deleting you need to do this otherwise it gives runtime error
//     delete(dummy);
    
    
//     return head;
// }
// // Approach 2
// #include <bits/stdc++.h> 
// #include <bits/stdc++.h> 
// /************************************************************

//     Following is the linked list node structure.
    
//     template <typename T>
//     class Node {
//         public:
//         T data;
//         Node* next;

//         Node(T data) {
//             next = NULL;
//             this->data = data;
//         }

//         ~Node() {
//             if (next != NULL) {
//                 delete next;
//             }
//         }
//     };

// ************************************************************/
// // TC = O(m+n) sc=O(m+n)
// Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
// {
//      if(first==NULL) return second;
//     if(second==NULL) return first;
            

//     if(first->data<second->data)
//     {
        
//         first->next=sortTwoLists(first->next, second);
//         return first;
//     }
//     else
//     {
        
//         second->next=sortTwoLists(first, second->next);
//         return second;
//     }
    
// }
// Approach 3
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
// TC=O(m+n) sc=O(1)
Node<int>* solve(Node<int>* first, Node<int>* second)
{
    if(first->next==NULL) // if only one node is present in first list
    {
        first->next=second;
        return first;
    }
    Node<int>* prev=first;
    Node<int>* temp=first->next;
    Node<int>* curr=second;
    Node<int>* temp2=curr;
    while(curr!=NULL && temp!=NULL)
    {
      if (curr->data <= temp->data && curr->data >= prev->data) {
          // adding node in the first list
        prev->next = curr;
        temp2 = curr->next;
        curr->next = temp;
        // updating
        prev = curr;
        curr = temp2;
      }
      else{
          prev=temp;
          temp=temp->next;
      }
      
    }
    if(curr!=NULL) prev->next=curr;
    return first;
}
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first==NULL) return second;
    if(second==NULL) return first;
    if(first->data<second->data)
    {
       return solve(first, second);
    }
    else{
       return solve(second,first);
    }
}


