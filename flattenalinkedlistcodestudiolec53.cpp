// in this question, we have to print the nodes linked child wise so i have replaced next with child everywhere in the merge function
// here we have only 1 approach but we can do it both iteratively and recursively but 
// recursive is better and easier whereas iterative gives tle
// #include <bits/stdc++.h> 
// #include <bits/stdc++.h> 
// /****************************************************************

//     Following is the class structure of the Node class:

// class Node {
// public:
// 	int data;
// 	Node* next;
// 	Node* child;

// 	Node(int data) {
// 		this->data = data;
// 		this->next = NULL;
// 		this->child = NULL;
// 	}
// };

// *****************************************************************/
// // iterative
// void insertattail(Node* &tail,Node* temp)
// {
//           tail->child=temp;
//           tail=temp;
// }
// Node* merge(Node* left, Node* right)
// {
//     Node* dummy=new Node(-1);
//     Node* dummytail=dummy;
//     Node* temp1=left;
//     Node* temp2=right;
//     while(temp1!=NULL && temp2!=NULL)
//     {
//         if((temp1->data)<(temp2->data))
//         {
//             Node* c=temp1->child;
//             temp1->child=NULL;
//               insertattail(dummytail,temp1);
//                       temp1=c;

//         }
//         else
//         {
//            Node* n=temp2->child;
//             temp2->child=NULL;
//             insertattail(dummytail,temp2);
//                     temp2=n;

//         }
//     }

//     if(temp1!=NULL)
//     {
//         dummytail->child=temp1;
        
//     }
//     if (temp2 != NULL) {
//       dummytail->child = temp2;
//     }
//     Node *head = dummy->child;
//     dummy->child = NULL; 
                        
//     delete (dummy);

//     return head;
// }
// Node* flattenLinkedList(Node* head) 
// {
// 	  if(!head->next)
//         return head;

//     Node *f = head,*s = head->next,*nex = head->next->next;
    
//     while(s){
//         f->next = NULL;
//         s->next = NULL;
        
//         Node* m = merge(f,s);
//         f = m;
//         s = nex;
//         if(nex)
//             nex = nex->next;
        
//     }
    
//     return f;

// }
// recursive 
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
// TC=O(n*c) and SC=O(n)
void insertattail(Node* &tail,Node* temp)
{
          tail->child=temp;
          tail=temp;
}
Node* merge(Node* left, Node* right)
{
    Node* dummy=new Node(-1);
    Node* dummytail=dummy;
    Node* temp1=left;
    Node* temp2=right;
    while(temp1!=NULL && temp2!=NULL)
    {
        if((temp1->data)<(temp2->data))
        {
            Node* c=temp1->child;
            temp1->child=NULL;
              insertattail(dummytail,temp1);
                      temp1=c;

        }
        else
        {
           Node* n=temp2->child;
            temp2->child=NULL;
            insertattail(dummytail,temp2);
                    temp2=n;

        }
    }

    if(temp1!=NULL)
    {
        dummytail->child=temp1;
        
    }
    if (temp2 != NULL) {
      dummytail->child = temp2;
    }
    Node *head = dummy->child;
    dummy->child = NULL; 
                        
    delete (dummy);

    return head;
}
Node* flattenLinkedList(Node* head) 
{
	if(head->next==NULL) return head;
	Node* down=head;
	Node* right=down->next;
	down->next=NULL;
	right=flattenLinkedList(right);
	Node* ans=merge(down,right);
	return ans;
}
