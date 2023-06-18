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
 // Recursive approach
//  class Solution {
// public:
//     int sumOfLeftLeaves(TreeNode* root) {
//         if(root==NULL) return 0;
//         int ans=0;
//         if(root->left)
//         {
//             if(root->left->left==NULL && root->left->right==NULL) ans+=root->left->val;
//             else ans+=sumOfLeftLeaves(root->left);
//         }
//         ans+=sumOfLeftLeaves(root->right);
//         return ans;
//     }
// };
 // Iterative approach
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
            {
                if(temp->left->left==NULL && temp->left->right==NULL) ans+=temp->left->val;
                else q.push(temp->left);
            }
            if(temp->right)
            {
                if(temp->right->left!=NULL || temp->right->right!=NULL) q.push(temp->right);
            }
        }
        return ans;
    }
};