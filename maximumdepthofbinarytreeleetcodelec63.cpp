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
 // recursive solution DFS
 // TC=O(N) AS ALL NODES ARE VISITED AND SC=O(N) AS IN A SKEWED TREE ALL NODES WILL COME IN THE RECURSION STACK
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         if(root==NULL) return 0;
//         int leftdepth=maxDepth(root->left);
//         int rightdepth=maxDepth(root->right);
//         return max(leftdepth,rightdepth)+1;
//     }
// };
// iterative solution BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int cnt=0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                cnt++;
             if(!q.empty()) q.push(NULL);
            }
            else
            {
              if(temp->left) q.push(temp->left);
              if(temp->right) q.push(temp->right);
            }
        }
        return cnt;
    }
};