/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 // inorder traversal if sorted then it is a bst
class Solution {
public:
bool check(TreeNode* root,TreeNode*& prev)
{
    if(root==NULL) return true;
   bool leftcheck= check(root->left,prev);
   if(leftcheck==false) return false;
   if(prev!=NULL && root->val<=prev->val) return false;
   prev=root;

    bool rightcheck=check(root->right,prev);
    if(rightcheck==false) return false;
    return true;
}
 bool isValidBST(TreeNode* root) {
       if(root==NULL) return true;
    TreeNode* prev=NULL;
    return check(root,prev);
    }
// Approach 2
// we are checking the range for each node
//  bool check(TreeNode* root, int min, int max)
//  {
//      if(root==NULL) return true;
//      if(root->val>max || root->val<min) return false;
//      bool leftcheck,rightcheck;
//      if(root->val==INT_MIN) // to avoid integer overflow
//      {
//        if(root->left==NULL) leftcheck=true;
//        else leftcheck=false;
//      }
//      else
//      leftcheck=check(root->left,min,root->val-1);
//      if(leftcheck==false) return false;
//      if(root->val==INT_MAX)
//      {
//        if(root->right==NULL) rightcheck=true;
//        else rightcheck=false;
//      }
//      else
//      rightcheck=check(root->right,root->val+1,max);
//      if(rightcheck==false) return false;
//      return true;
//  }
//  bool isValidBST(TreeNode* root) {
//        int min=INT_MIN;
//        int max=INT_MAX;
//        return check(root,min,max);
//     }
// the following wont work as we have to check whole left and right subtrees
    // bool isValidBST(TreeNode* root) {
    //      if(root==NULL) return true;
    // if(root->left!=NULL && root->left->val>=root->val) return false;
    // if(root->right!=NULL && root->right->val<=root->val) return false;
    // bool left=isValidBST(root->left);
    // if(left==false) return false;
    // bool right=isValidBST(root->right);
    // if(right==false) return false;
    // return true;
    // }
};