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
 class Solution {
public:
void path(TreeNode* root, int pathnum, vector<int>& ans)
{
    if(root==NULL) return;
    if( root->left==NULL && root->right==NULL)
       {
           pathnum=pathnum*10+root->val;
           ans.push_back(pathnum);
           return;
       }
       pathnum=pathnum*10+root->val;
       path(root->left,pathnum,ans);
       path(root->right,pathnum,ans);
}
    int sumNumbers(TreeNode* root) {
        vector<int> ans;
        int pathnum=0;
        path(root,pathnum,ans);
        int finalans=0;
        for(int i=0;i<ans.size();i++)
        {
            finalans+=ans[i];
        }
        return finalans;

    }
};
 // iterative approach
// class Solution {
// public:
//     int sumNumbers(TreeNode* root) {
//         int totalsum=0;
//         queue<pair<TreeNode*,int>> q;
//         q.push({root,0});
//         while(!q.empty())
//         {
//             TreeNode* temp=q.front().first;
//             int cursum=q.front().second;
//             q.pop();
//             cursum=cursum*10+temp->val;
//             if(temp->left==NULL && temp->right==NULL) totalsum+=cursum;
//             if(temp->left) q.push({temp->left,cursum});
//             if(temp->right) q.push({temp->right,cursum});
//         }
//         return totalsum;
//     }
// };