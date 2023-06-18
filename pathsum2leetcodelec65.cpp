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
 void check(TreeNode* root, int targetSum, int cursum, vector<int> subans, vector<vector<int>>& ans)
 {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
           cursum+=root->val;
           if(cursum==targetSum)
           {
             subans.push_back(root->val);
             ans.push_back(subans);
             return;
           }
        }
        cursum+=root->val;
        subans.push_back(root->val);
        check(root->left,targetSum,cursum,subans,ans);
        check(root->right,targetSum,cursum,subans,ans);
 }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         int cursum=0;
         vector<vector<int>> ans;
         vector<int> subans;
         check(root,targetSum,cursum,subans,ans);
        return ans;
    }
};