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
// TC=O(n) as unordered map is used and it has a TC of O(1)
void createmapping(vector<int>& inorder, int n, unordered_map<int,int>& nodeToindex)// by reference hi karna hoga nahi toh solve function mein empty map chala jaaega
{
    for(int i=0;i<n;i++)
    {
        nodeToindex[inorder[i]]=i;
    }
}
    TreeNode* solve(vector<int>& inorder,vector<int>& preorder, int n, int& index, int inorderstart, int inorderend,unordered_map<int,int>& nodeToindex) // pehle tle marega but by reference pass karne se unnecessary copying nahi hoga so it gets accepted
    {
        if(index==n || inorderstart>inorderend) return NULL;
        int element=preorder[index];
        TreeNode* root=new TreeNode(element);
        int pos=nodeToindex[element];
        index++;
        root->left=solve(inorder,preorder,n,index,inorderstart,pos-1,nodeToindex);
        root->right=solve(inorder,preorder,n,index,pos+1,inorderend,nodeToindex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int preorderindex=0;
        int inorderstart=0;
        int inorderend=n-1;
        unordered_map<int,int> nodeToindex;
        createmapping(inorder,n,nodeToindex);
        TreeNode* ans=solve(inorder,preorder,n,preorderindex,inorderstart,inorderend,nodeToindex);
        return ans;
        
    }
};
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// TC=O(n^2)
// class Solution {
// public:
// int findPosition(vector<int>& inorder, int element,int inorderstart, int inorderend)
//     {
//         for(int i=inorderstart;i<=inorderend;i++)
//         {
//             if(inorder[i]==element) return i;
//         }
//         return -1;
//     }
//     TreeNode* solve(vector<int>& inorder,vector<int>& preorder, int n, int& index, int inorderstart, int inorderend)
//     {
//         if(index==n || inorderstart>inorderend) return NULL;
//         int element=preorder[index];
//         TreeNode* root=new TreeNode(element);
//         int pos=findPosition(inorder,element,inorderstart,inorderend); // this is done for duplicate elements
//         index++;
//         root->left=solve(inorder,preorder,n,index,inorderstart,pos-1);
//         root->right=solve(inorder,preorder,n,index,pos+1,inorderend);
//         return root;
//     }
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         int n=preorder.size();
//         int preorderindex=0;
//         int inorderstart=0;
//         int inorderend=n-1;
//         TreeNode* ans=solve(inorder,preorder,n,preorderindex,inorderstart,inorderend);
//         return ans;
        
//     }
// };