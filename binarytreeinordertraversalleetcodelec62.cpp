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
 // using a stack
 // dry run if you dont understand
 // SC=O(n)
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(root==NULL) return ans;
//         stack<TreeNode*> st;
//         TreeNode* curr=root;
//         while(curr!=NULL || st.empty()==0)
//         {
//             while(curr!=NULL)
//             {
//                 st.push(curr);
//                 curr=curr->left;
//             }
//             TreeNode* temp=st.top();
//             ans.push_back(temp->val);
//             curr=st.top()->right;
//             st.pop();   
//         }
//         return ans;
//     }
// };
// Morris traversal
// refer to striver video if you dont understand
// TC O(n) and SC=O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};