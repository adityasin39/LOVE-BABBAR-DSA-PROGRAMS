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
 // best approach as it has SC=O(h) as we are using bst iterator.
 // we use next and before here. To implement before we use bool reverse
 // before will give reverse inorder ie right node left
 // rest is same as 2nd approach which is 2 pointer
 class BSTIterator {
public:
stack<TreeNode*> st;
bool reverse;
    BSTIterator(TreeNode* root,bool reverse) {
         this->reverse=reverse;
         pushAll(root);
    }
    void pushAll(TreeNode* node)
    {
        if(reverse)
        for(;node!=NULL;node=node->right) st.push(node);
        else 
        for(;node!=NULL;node=node->left) st.push(node);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        if(reverse) pushAll(temp->left);
        else pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        return false;
    }
};
 class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
     BSTIterator left(root,false);
     BSTIterator right(root,true);
     int s=left.next();
     int e=right.next();
     while(s<e)
     {
         if(s+e==k) return true;
         if(s+e>k) 
         {
             e=right.next();
         }
         else s=left.next();
     } 
     return false;
    }
};
// 2nd approach
// class Solution {
// public:
// void solve(TreeNode* root, int k, vector<int>& inorder)
// {
//     if(root==NULL) return;
//     solve(root->left,k,inorder);
//     inorder.push_back(root->val);
//     solve(root->right,k,inorder);
// }
//     bool findTarget(TreeNode* root, int k) {
//         vector<int> inorder;
//         solve(root,k,inorder);
// 2 pointer
//         int s=0;
//         int e=inorder.size()-1;
//         while(s<e)
//         {
//             int sum=inorder[s]+inorder[e];
//             if(sum==k) return true;
//             if(sum>k) e--;
//             else s++;
//         }
//         return false;
//     }
// };