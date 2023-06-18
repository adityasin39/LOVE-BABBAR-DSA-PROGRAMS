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
 //recursive DFS
// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//        if(root==NULL) return 0;
//        int left=minDepth(root->left);
//        int right=minDepth(root->right);
//        if(left==0||right==0) return max(left,right)+1; // for skewed
//        else return min(left,right)+1;
//     }
// };
// iterative BFS 
class Solution {
public:
    int minDepth(TreeNode* root) {
       if(root==NULL) return 0;
       queue<TreeNode*> q;
       q.push(root);
       q.push(NULL);
       int cnt=0;
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
               if(temp->left==NULL && temp->right==NULL) {
               return cnt+1;
           }
               if(temp->left) q.push(temp->left);
              if(temp->right) q.push(temp->right);
           }
       }
       return 0;     
    }
};