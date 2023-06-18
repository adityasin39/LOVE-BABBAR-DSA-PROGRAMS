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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newnode=new TreeNode(val);
        if(root==NULL) return newnode;
        TreeNode* originalroot=root;
       while(1)
       {
           if(val<root->val)
           {
               if(root->left==NULL)
               {
                   root->left=newnode;
                   return originalroot;
               }
               root=root->left;
           }
             if(val>root->val)
           {
               if(root->right==NULL)
               {
                   root->right=newnode;
                   return originalroot;
               }
               root=root->right;
           }
       }
    }
};
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         if(root==NULL)
//         {
//             TreeNode* newnode=new TreeNode(val);
//             return newnode;
//         }
//         if(val<root->val)
//         {
//            root->left= insertIntoBST(root->left,val);
//         }
//         if(val>root->val)
//         {
//             root->right=insertIntoBST(root->right,val);
//         }
//         return root;
//     }
// };