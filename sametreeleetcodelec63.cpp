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
class Solution {
public:
    bool traverse(TreeNode* p,TreeNode* q)
    {
         if(p==NULL && q==NULL) return true;
        if(p==NULL || q==NULL) return false;
       bool left= traverse(p->left,q->left);
       if(left==false) return false;
       bool right= traverse(p->right,q->right);
       if(right==false) return false;
        if(p->val!=q->val) return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
       bool ans=traverse(p,q);
       return ans;
        
    }
};