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
 // TC=O(N)LOG(N) AND SC=O(N)
 // IF YOU DONT UNDERSTAND THEN REFER TO LOVE BABBAR
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int,map<int,multiset<int>>> mp;
        queue<pair<pair<int,int>,TreeNode*>> q;
        q.push(make_pair(make_pair(0,0),root));
        while(!q.empty())
        {
            TreeNode* temp=q.front().second;
            int vlevel=q.front().first.first;
            int level=q.front().first.second;
            q.pop();
            mp[vlevel][level].insert(temp->val);
            if(temp->left) q.push(make_pair(make_pair(vlevel-1,level+1),temp->left));
            if(temp->right) q.push(make_pair(make_pair(vlevel+1,level+1),temp->right));
        }
     
     for(auto i: mp)
     {
         vector<int> subans;
         for(auto j:i.second)
         {
             for(auto k:j.second)
             subans.push_back(k);
         }
         ans.push_back(subans);
     }
        return ans;
    }
};