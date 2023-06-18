/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 // one more approach which has constant space is DSW algo which is as follows
//  While you may not be able to 'invent' this solution, you can keep the key ideas of DSW in mind:

// Convert the BST into a vine (a normalised BST) using either (but exclusively) left or right rotations.
// Balance the vine using the other type of rotation (not used in step 1).
 // first we get the inorder traversal in a vector then to make a balanced bst that too with minimum height we can divide the array in two parts recursively so that the height is minimum.
class Solution {
public:
void makeitsorted(TreeNode* root, vector<TreeNode*>& inorder)
{
    if(root==NULL) return;
    makeitsorted(root->left,inorder);
    inorder.push_back(root);
    makeitsorted(root->right,inorder);
}
TreeNode* makeitbalanced(vector<TreeNode*>& inorder,int start, int end )// by reference se time pe boht farak padta hai
{
    if(start>end) return NULL;
    int mid=start+(end-start)/2;
    inorder[mid]->left=makeitbalanced(inorder,start,mid-1);
    inorder[mid]->right=makeitbalanced(inorder,mid+1,end);
    return inorder[mid];
}
    TreeNode* balanceBST(TreeNode* root) {
       vector<TreeNode*> inorder;
       makeitsorted(root,inorder);
       int start=0;
       int end=inorder.size()-1;
      TreeNode* ans= makeitbalanced(inorder,start,end); 
      return ans;

    }
};