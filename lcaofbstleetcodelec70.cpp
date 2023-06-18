/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// recursive approach.
// iterative approach will work the same based on the two conditions
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;// no requirement of base case here
        if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left,p,q);
        if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right,p,q);
        return root;// if p or q is equal to root or root>p && root<q or root<p && root>q
    }
};