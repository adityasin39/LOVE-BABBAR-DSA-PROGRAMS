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
 //recursive approach
// class Solution {
// public:
//   bool check(TreeNode* p, TreeNode* q)
//   {
//     if(p==NULL && q==NULL) return true;
//     if(p==NULL || q==NULL) return false;
//    bool left= check(p->left,q->right);
//    if(left==false) return false;
//    bool right= check(p->right,q->left);
//    if(right==false) return false;
//    if(p->val!=q->val) return false;
//    return true;
//   }
//     bool isSymmetric(TreeNode* root) {
//        bool ans=check(root->left,root->right);
//       return ans;
//     }
// };
// iterative approach
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        if(root->left==NULL || root->right==NULL) return false;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        while(!q.empty())
        {
            TreeNode* temp1=q.front();
            q.pop();
            TreeNode* temp2=q.front();
            q.pop();
            if((temp1==NULL && temp2!=NULL) || (temp1!=NULL && temp2==NULL)) return false;
            if(temp1==NULL && temp2==NULL) continue;
            if(temp1->val!=temp2->val) return false;
            if(temp1->left) q.push(temp1->left);
            else q.push(NULL);
            if(temp2->right) q.push(temp2->right);
            else q.push(NULL);
            if(temp1->right) q.push(temp1->right);
            else q.push(NULL);
            if(temp2->left) q.push(temp2->left);
            else q.push(NULL);
        }
        return true;
    }
};