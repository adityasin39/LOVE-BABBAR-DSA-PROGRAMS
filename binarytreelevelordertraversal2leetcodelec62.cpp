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
 // Approach 1 using recursion
// class Solution {
// public:
// int depth(TreeNode* root)
// {
//     if(root==NULL) return 0;
//     int leftdepth=depth(root->left);
//     int rightdepth=depth(root->right);
//     return max(leftdepth,rightdepth)+1;
// }
//  vector<vector<int>> reverselevelorder(vector<vector<int>> ans,TreeNode* root, int level)
// {
//     if(root==NULL) return ans;
//     ans[level].push_back(root->val);
//     ans=reverselevelorder(ans,root->left,level-1);
//     ans=reverselevelorder(ans,root->right,level-1);
//     return ans;
// }
//     vector<vector<int>> levelOrderBottom(TreeNode* root) {
//         vector<vector<int>> ans;
//         if(root==NULL) return ans;
//         int d=depth(root);
//      ans= reverselevelorder(ans,root,d-1);
//        return ans;
//     }
// };
// Approach 2 using iteration 
// we have used stack just to reverse level order traversal done by queue
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> answer;
        
        queue<TreeNode*> q;
        if(root==NULL)
            return answer;
        
        q.push(root);
        
        stack<vector<int>>s;
                
        while(!q.empty())
        {
            vector<int>ans;
            int len=q.size();
            
            while(len--)
            {
                TreeNode* temp=q.front();
                q.pop();
                ans.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);                
            }
            s.push(ans);
        }
        
        while(!s.empty())
        {
            answer.push_back(s.top());
            s.pop();
        }
        
        return answer;
        
    }
};