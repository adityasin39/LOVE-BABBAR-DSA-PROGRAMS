#include <bits/stdc++.h> 
/*************************************************
        Following is the structure of class Node:
     
        class Node{
        public:
            int data;
            Node* next;
            
            Node(int data){
                this->data = data;
                this->next = NULL;
            }
            
        }
**************************************************/
//yahi approach use karna hai to solve this problem
// floyd cycle detection algo
//tc is O(n) and sc is O(1)
// kyonki with each iteration the distance between slow and fast pointers decrease so they will definitely meet
bool isCircular(Node *head) {
      if(head==NULL) return true;
      if(head->next==NULL) return false;
      Node* slow=head;
      Node* fast=head;
      while(fast!=NULL && fast->next!=NULL)
      {
          slow=slow->next;
          fast=fast->next->next;
          if(slow==fast) break;
      }
      if(slow==fast && slow==head) return true;
      else return false;
   }
// a linked list with a single node can also be circular
// this code is basically for linked lists which do not have cycle in between like 1 2 3 5 2 4
// tc is O(n) and sc is O(1)
// bool isCircular(Node* head){
//     if(head==NULL) return true;
//     Node* temp=head;
//     do
//     {
//        temp=temp->next;
//     }while(temp!=head && temp!=NULL);
//     if(temp==head) return true;
//     else return false;
// }
// ye nahi chal raha as there are some errors on codestudios end. tc=O(n) sc-O(n)
// bool isCircular(Node* head){
//     if(head==NULL) return true;
//         Node* temp=head;
//     map<Node*, bool> m;
//    do
//    {
//        m[temp]=true;
//       temp=temp->next;
//    }while(temp!=NULL && temp!=head && m[temp]==false);


//     if(temp==NULL)
//              return false;
//         if(m[temp]==true && temp != head)
//             return false;
//         return true;
// }
// ye  chal raha hai
//  #include <bits/stdc++.h> 

//     bool isCircular(Node *head) {

//     if(head==NULL) return 1;

//     if(head->next==NULL) return 0;

//     if(head->next==head) return 1;

//     Node*temp = head->next;

//     int val = head->data;

//     int cnt=0;

//     while(temp!=NULL){

//         if(temp->data == val ) return 1;

//         cnt++;

//         temp = temp->next;

//         if(cnt>10000) return 0;

//     }

//     return 0;

// }
// ye bhi chal raha hai
// bool isCircular(Node* head){    
//     // Write your code here
//         if(head==NULL)
//             return true;
//         if(head->next==NULL)        
//             return false;    
//         if(head->next==head)
//             return true;        
//         Node* temp=head;
//         while(temp!=NULL && temp->data!=0){
//             temp->data = 0;
//             temp=temp->next;
//         }             
//         if(temp==NULL)
//              return false;
//         if(temp->data==0 && temp != head)
//             return false;
//         return true;
//}
