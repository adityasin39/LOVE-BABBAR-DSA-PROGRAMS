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
 // approach 1
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> subans;
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                ans.push_back(subans);
                subans.resize(0);
               if(!q.empty()) q.push(NULL);
            }
            else
            {
                subans.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return ans;
    }
};
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
 // approach 2
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        vector<int> subans;
        queue<TreeNode*> q;
        q.push(root);
        subans.push_back(root->val);
        ans.push_back(subans);
        while(!q.empty())
        {
            vector<int> sublist;
            int levelnum=q.size();
            for(int i=0;i<levelnum;i++)
            {
                if(q.front()->left)
                { 
                    q.push(q.front()->left);
                sublist.push_back(q.front()->left->val);
                }
                if(q.front()->right) 
                {
                   q.push(q.front()->right);
                   sublist.push_back(q.front()->right->val);
                }
                q.pop();
            }
            if(sublist.size()>0)
            ans.push_back(sublist);
            
        }
        return ans;

    }
};