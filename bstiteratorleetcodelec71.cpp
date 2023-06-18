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
 //best approach
 // we have used the concept of inorder traversal that is left node right
 // here SC=O(h) 
 // if you dont understand then refer to striver video tree lec50
class BSTIterator {
public:
stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        
        pushAll(root);
    }
    void pushAll(TreeNode* node)
    {
        for(;node!=NULL;node=node->left) st.push(node);
    }
    
    int next() {
        TreeNode* temp=st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    
    bool hasNext() {
        if(!st.empty()) return true;
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */