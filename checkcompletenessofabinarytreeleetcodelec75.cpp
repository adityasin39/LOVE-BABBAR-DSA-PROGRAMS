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
 //the logic applied here is that if at any node, the left child is null and the right child is present then it is false.Then if at any node the right child becomes null that means if there are nodes in the next level which have children then it is false.
 // you can also do this by dfs by considering the fact that if the left child index i.e. 2*i is out of the number of nodes then it is false.Similarly if the right child index ie. 2*i+1 is out of the number of nodes then false.
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool end=false;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left==NULL && temp->right!=NULL) return false;
                if(temp->left)
                { 
                    if(end==true)return false;
                    else q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                } 
                else end=true;
            }
        }
        return true;
    }
};