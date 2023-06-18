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
 // BEST APPROACH TC=O(N).
 // WE ARE USING A HASHMAP TO STORE DIFFERENT CURSUM AND THE NUMBER OF PATHS CORRESPONDING TO IT.
 // WHENEVER WE GET A CURSUM=TARGET THEN WE INCREMENT
 // WE ALSO CHECK IF THERE EXISTS CURSUM-TARGET IN THE MAP.
 // WE HAVE TO BACKTRACK TOO TO REMOVE VALUES FROM THE HASHMAP
 class Solution {
public:
 void findpath(TreeNode* root, unordered_map<long long,int>& mp, long long cursum, int targetSum, int& count)
 {
     if(root==NULL) return;
     cursum+=root->val;
     if(cursum==targetSum) count++;
     if(mp.find(cursum-targetSum)!=mp.end()) count+=mp[cursum-targetSum];
     mp[cursum]++;
     findpath(root->left,mp,cursum,targetSum,count);
     findpath(root->right,mp,cursum,targetSum,count);
     mp[cursum]--;
 }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long,int> mp;
        int cursum=0;
        int count=0;
        findpath(root,mp,cursum,targetSum,count);
        return count;
    }
};
 //TC=O(N^2) AS WE ARE GOING ON EACH NODE AND THEN FINDING ALL THE PATHS BY RECURSION
// class Solution {
// public:
// int count=0;
// void dfs(TreeNode* root, long long targetSum)
// {
//     if(root==NULL) return;
//     if(root->val==targetSum) count++;
//     dfs(root->left,targetSum-root->val);
//     dfs(root->right,targetSum-root->val);

// }
//     int pathSum(TreeNode* root, long long targetSum) {
//         if(root==NULL) return 0;
//         dfs(root,targetSum);
//         pathSum(root->left,targetSum);
//         pathSum(root->right,targetSum);
//         return count;
//     }
// };