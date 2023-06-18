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
 // using two stacks
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//          vector<int> ans;
//          if(root==NULL) return ans;
//          stack<TreeNode*> st1;
//          stack<TreeNode*> st2;
//          st1.push(root);
//          while(!st1.empty())
//          {
//            TreeNode* temp=st1.top();
//            st1.pop();
//            st2.push(temp);
//            if(temp->left) st1.push(temp->left);
//            if(temp->right) st1.push(temp->right);
//          }
//          while(!st2.empty())
//          {
//              ans.push_back(st2.top()->val);
//              st2.pop();
//          }
//          return ans;

//     }
// };
// using 1 stack 
// refer to striver if you dont understand
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(root==NULL) return ans;
//         stack<TreeNode*> st;
//         TreeNode* curr=root;
//         while(!st.empty() || curr!=NULL)
//         {
//           if(curr!=NULL)
//           {
//             st.push(curr);
//             curr=curr->left;
//           }
          
//           else{
//             TreeNode* temp=st.top()->right;
//             if(temp==NULL)
//             {
//               temp=st.top();
//               st.pop();
//               ans.push_back(temp->val);
//               while(!st.empty() && temp==st.top()->right)
//               {
//                   temp=st.top();
//               st.pop();
//               ans.push_back(temp->val);
//               }
//             }
//               else
//               { 
//                 curr=temp;
//               }
//             }
//         }
        
//         return ans;
//     }
// };
// Morris traversal similar to preorder. The only change is replace left with right
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->right==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->left;
            }
            else
            {
                TreeNode* prev=curr->right;
                while(prev->left!=NULL && prev->left!=curr) prev=prev->left;
                if(prev->left==NULL)
                {
                    prev->left=curr;
                     ans.push_back(curr->val);
                    curr=curr->right;
                }
                else
                {
                    prev->left=NULL;
                    
                    curr=curr->left;
                }
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};