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
// MORRIS TRAVERSAL. IF YOU DONT UNDERSTAND THEN REFER TO striver VIDEO
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        TreeNode* curr=root;
        while(curr!=NULL)
        {
            if(curr->left!=NULL)
            {
                TreeNode* prev=curr->left;
                while(prev->right!=NULL) prev=prev->right;
                prev->right=curr->right;
                curr->right=curr->left;
            }
            curr->left=NULL;
            curr=curr->right;
            
        }
    }
};
// recursive. if you dont understand then refer to strivers video
// TreeNode* prev=NULL;
//  void flatten(TreeNode* root) {
//         if(root==NULL) return;
//         flatten(root->right);
//         flatten(root->left);
//         root->right=prev;
//         root->left=NULL;
//         prev=root;
//     }
// };
// // SC=O(N)
//class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(root==NULL) return;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty())
//         {
//             TreeNode* temp=st.top();
//             st.pop();
//             if(temp->right) st.push(temp->right);
//             if(temp->left) st.push(temp->left);
//             temp->left=NULL;
//             if(!st.empty())
//             temp->right=st.top();
//             else temp->right=NULL;
//         }
//     }
// };
