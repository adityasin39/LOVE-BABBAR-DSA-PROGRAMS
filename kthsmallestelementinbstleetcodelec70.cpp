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
// there are a lot of solutions but this is the best as it takes constant time.
// you cant break the loop as soon as you get the answer as the threads need to be broken
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* curr=root;
        int ans;
        while(curr!=NULL)
        {
            if(curr->left==NULL)
            {
                k--;
                if(k==0) ans= curr->val;
                curr=curr->right;
            }
            else
            {
                TreeNode* prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr)
                {
                    prev=prev->right;
                }
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    k--;
                    if(k==0) ans= curr->val;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};