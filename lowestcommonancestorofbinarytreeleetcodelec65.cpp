/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // best approach
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        if(root->val==p->val) return root;
        if(root->val==q->val) return root;
       TreeNode* left= lowestCommonAncestor(root->left,p,q);
       TreeNode* right= lowestCommonAncestor(root->right,p,q);
       if(left==NULL && right==NULL) return NULL;
       if(left==NULL && right!=NULL) return right;
       if(right==NULL && left!=NULL) return left;
       return root;
    }
};
//2nd approach brute force approach
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution {
// public:
//  void lca(TreeNode* root, TreeNode* p, TreeNode* q, vector<TreeNode*>& v1, vector<TreeNode*>& v2, bool& foundp, bool& foundq)
//  {
//       if(root==NULL) return;
//       if(root->val!=p->val && foundp==false) v1.push_back(root);
//       else
//       {
//         foundp=true;
//       }
//       if(root->val!=q->val && foundq==false) v2.push_back(root);
//        else
//       {
//         foundq=true;
//       }
//       lca(root->left,p,q,v1,v2,foundp,foundq);
//       lca(root->right,p,q,v1,v2,foundp,foundq);
//        if(foundp==false) v1.pop_back();
//       if(foundq==false) v2.pop_back();
      
//  }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> v1;
//         vector<TreeNode*> v2;
//         bool foundp=false;
//         bool foundq=false;
//         lca(root,p,q,v1,v2,foundp, foundq);
//         v1.push_back(p);
//         v2.push_back(q);
//         int size1=v1.size();
//         int size2=v2.size();
//         for(int i=size1-1;i>=0;i--)
//         {
//             for(int j=size2-1;j>=0;j--)
//             {
//                 if((v1[i])->val==(v2[j])->val) return v1[i];
//             }
//         }
//          return NULL;
//     }
   
// };