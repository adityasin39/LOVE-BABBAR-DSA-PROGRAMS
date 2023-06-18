#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
// best approach iterative one
// here we can see that the predecessor of a given node is the the rightmost node in the left subtree and similarly the successor of a node is the leftmost node in the right subtree.
// if in the case of predecessor, left subtree doesnt exist then we can save the possible predecessor while finding the key node
pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    if(root==NULL) return {-1,-1};
  BinaryTreeNode<int>* temp=root;
   BinaryTreeNode<int>* pre=NULL;
  BinaryTreeNode<int>* suc=NULL;
  while( temp->data!=key)
  {
    if (temp->data > key) {
        suc = temp;
      temp = temp->left;
      
    } else {
         pre=temp;
      temp = temp->right;
     
    }
  }
 
  BinaryTreeNode<int>* temp1=temp->left;
  while(temp1!=NULL && temp1->right)
  {
      temp1=temp1->right;
  }
  if(temp1) pre=temp1;
  BinaryTreeNode<int>* temp2=temp->right;
  while(temp2!=NULL && temp2->left)
  {
      temp2=temp2->left;
  }
  if(temp2) suc=temp2;
  if(pre==NULL && suc==NULL) return {-1,-1};
  if(pre==NULL) return {-1,suc->data};
  if(suc==NULL) return {pre->data,-1};
  return {pre->data,suc->data};
}
// recursive approach using inorder traversal
// void solve(BinaryTreeNode<int>* root, int key, BinaryTreeNode<int>*& prev, BinaryTreeNode<int>*& next,BinaryTreeNode<int>*& finalprev,bool& keyfound)
// {
//     if(root==NULL) return;
//     solve(root->left,key,prev,next,finalprev,keyfound);
//     if(keyfound==true)
//     {
//         next=root;
//         keyfound=false;
//         return;
//     }
//     if(root->data==key)
//     {
//        keyfound=true;
//        finalprev=prev;
//     }
    
//     prev=root;
//     solve(root->right,key,prev,next,finalprev,keyfound);

// }
// pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
// {
//     BinaryTreeNode<int>* prev=NULL;
//     BinaryTreeNode<int>* next=NULL;
//     BinaryTreeNode<int>* finalprev=NULL;
//     bool keyfound=false;
//     solve(root,key,prev,next,finalprev,keyfound);
//     if(finalprev==NULL && next==NULL) return {-1,-1};
//     if (finalprev == NULL) {
//       return {-1,next->data};
//     }
//     if (next == NULL) {
//       return {finalprev->data,-1};
//     }
//     return {finalprev->data,next->data};
// }
