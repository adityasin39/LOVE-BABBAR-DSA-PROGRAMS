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
 // recursive
 class Solution {
public:
bool check(TreeNode* root, int targetSum, int cursum)
 {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL)
        {
           cursum+=root->val;
           if(cursum==targetSum) return true;
           return false;
        }
        cursum+=root->val;
       bool left= check(root->left,targetSum,cursum);
        if(left==true) return true;
       bool right= check(root->right,targetSum,cursum);
        if(right==true) return true;
        return false;
 }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int cursum=0;
        bool ans=check(root,targetSum,cursum);
        return ans;
    }
};
 // iterative
// class Solution {
// public:
//     bool hasPathSum(TreeNode* root, int targetSum) {
//         if(root==NULL) return false;
//         queue<pair<TreeNode*,int>> q;
//         q.push({root,0});
//         while(!q.empty())
//         {
//             TreeNode* temp=q.front().first;
//             int cursum=q.front().second;
//             q.pop();
//             cursum+=temp->val;
//             if((temp->left==NULL && temp->right==NULL) && cursum==targetSum) return true;
//             if(temp->left) q.push({temp->left,cursum});
//             if(temp->right) q.push({temp->right,cursum});
//         }
//         return false;
//     }
// };