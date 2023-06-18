#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
// Approach 1 which is the brute force is to validate bst for each node and have the size of the bst too but this ofcourse takes n^2 time
// Approach 2 where the main idea is to do postorder traversal and from the bottom start checking if there exists a bst with its size
// To check if the subtree is a bst, we check if the root node is greater than the max value in the left subtree and if the root node is smaller than the min value in the right subtree
// if it is not a bst then we take the maxsize and pass mini as INT_MIN and maxi as INT_MAX so that the upper subtrees would never become a bst as the conditon would always fail
// if you dont understand then refer to strivers video
// we return min, max,maxsize to 
class Info
{
    public:
   int maxsize;
   int mini;
   int maxi;
   Info(int mini, int maxi, int maxsize)
   {
       this->maxsize=maxsize;
       this->mini=mini;
       this->maxi=maxi;
   }
};
Info largestbstsubtree(TreeNode<int>* root)
{
    if(root==NULL)
    {
        return Info(INT_MAX,INT_MIN,0);
    }
    Info leftsubtree=largestbstsubtree(root->left);
    Info rightsubtree=largestbstsubtree(root->right);
    // if it is a bst
    if(root->data>leftsubtree.maxi && root->data<rightsubtree.mini) 
    {
        return Info(min(root->data,leftsubtree.mini),max(root->data,rightsubtree.maxi),leftsubtree.maxsize+rightsubtree.maxsize+1);
    }
    // min(root->data,leftsubtree.mini) is done as there can be NULL thats why
    // if it is not a bst
    return Info(INT_MIN,INT_MAX,max(leftsubtree.maxsize,rightsubtree.maxsize));
}
int largestBST(TreeNode<int>* root) 
{
    return largestbstsubtree(root).maxsize;
}
