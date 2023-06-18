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
TreeNode* makeitbalanced(vector<int>& inorder,int start, int end )// by reference se time pe boht farak padta hai
{
    if(start>end) return NULL;
    int mid=start+(end-start)/2;
    TreeNode* root=new TreeNode(inorder[mid]);
    root->left=makeitbalanced(inorder,start,mid-1);
    root->right=makeitbalanced(inorder,mid+1,end);
    return root;
}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
       TreeNode* ans=makeitbalanced(nums,start,end);
       return ans; 
    }
};