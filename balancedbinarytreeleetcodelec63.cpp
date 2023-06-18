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
 // using -1 as a flag
 // TC=O(n) and SC=O(n)
class Solution {
public:
int height(TreeNode* root)
{
    if(root==NULL) return 0;
    int left=height(root->left);
    if(left==-1) return -1;
    int right=height(root->right);
    if(right==-1) return -1;
    if(left-right>1 || left-right<-1) return -1;
    return max(left,right)+1;
}
    bool isBalanced(TreeNode* root) {
        int ans=height(root);
        if(ans==-1) return false;
        else return true;
    }
};