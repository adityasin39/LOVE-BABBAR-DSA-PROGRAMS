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
 //Approach 1
// class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(root==NULL) return ans;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty())
//         {
//             TreeNode* temp=st.top();
//             st.pop();
//             ans.push_back(temp->val);
//             if(temp->right) st.push(temp->right);
//             if(temp->left) st.push(temp->left);
//         }
//         return ans;
//     }
// };
// Approach 2 
//class Solution {
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//          vector<int> ans;
//         if(root==NULL) return ans;
//         stack<TreeNode*> st;
//         TreeNode* curr=root;
//         while(curr!=NULL || st.empty()==0)
//         {
//             while(curr!=NULL)
//             {
//                 st.push(curr);
//                 ans.push_back(curr->val);
//                 curr=curr->left;
//             }
//             TreeNode* temp=st.top();
//             curr=st.top()->right;
//             st.pop();   
//         }
//         return ans;
//     }
// };
// Morris traversal with a one liner change from inorder Morris traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr) prev=prev->right;
                if(prev->right==NULL)
                {
                    prev->right=curr;
                     ans.push_back(curr->val);
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};