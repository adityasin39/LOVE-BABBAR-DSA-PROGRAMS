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
 // using recursion to do this approach is quite tough so using stack
class Solution {
public:
 TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode* root=new TreeNode(preorder[0]);
        st.push(root);
       
            for(int i=1;i<preorder.size();i++)
            {
            TreeNode* node=new TreeNode(preorder[i]);
            if(node->val<st.top()->val) st.top()->left=node;
            else
            {
                TreeNode* parent=NULL;
                while(!st.empty() && node->val>st.top()->val) 
                {
                    parent=st.top();
                    st.pop();
                }
                parent->right=node;
            }
            st.push(node);
            
        }
        return root;
    }
};
//Approach 2 which is better
// class Solution {
// public:
// TreeNode* makebst(vector<int>& preorder,int maxi, int mini, int& i)
// {
//     if(i==preorder.size()) return NULL;
//     if(preorder[i]>maxi || preorder[i]<mini) return NULL;
//     TreeNode* root=new TreeNode(preorder[i++]);
//     root->left=makebst(preorder,root->val,mini,i);
//     root->right=makebst(preorder,maxi,root->val,i);
//     return root;
// }
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int maxi=INT_MAX;
//         int mini=INT_MIN;
//         int i=0;
//         return makebst(preorder,maxi,mini,i);
//     }
// };
// Approach 3 is to sort the preorder and get the inorder and then you can make binary tree from preorder and inorder
// Approach 4 is to use takeinput function of the first video of LOVE BABBAR BST which will give TC=O(N*N)