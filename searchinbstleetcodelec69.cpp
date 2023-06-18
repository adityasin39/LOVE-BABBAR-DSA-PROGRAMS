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
 // recursive approach
// class Solution {
// public:
//     TreeNode* searchBST(TreeNode* root, int val) {
//         if(root==NULL) return NULL;
//         if(root->val==val) return root;
//         if(root->val<val)
//         {
//            TreeNode* left=searchBST(root->right,val);
//            return left;
//         }
//         if(root->val>val)
//         {
//             TreeNode* right=searchBST(root->left,val);
//             return right;
//         }
//         return NULL;
//     }
// };
// iterative approach
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
      while(root!=NULL && root->val!=val)
      {
          root=val<root->val?root->left:root->right;
      }
      return root;
    }
};