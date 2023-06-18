#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
//used bst iterator as the question demands SC=O(h)
class BSTIterator {
public:
stack<TreeNode<int>*> st;
    BSTIterator(TreeNode<int>* root) {
        
        pushAll(root);
    }
    void pushAll(TreeNode<int>* node)
    {
        for(;node!=NULL;node=node->left) st.push(node);
    }

    int next() {
      if(st.empty()) return -1;
      TreeNode<int> *temp = st.top();
      st.pop();
      pushAll(temp->right);
      return temp->data;
    }
};
TreeNode<int> *flatten(TreeNode<int> *root) {
    BSTIterator iterator(root);
     TreeNode<int> *prev = new TreeNode<int>(iterator.next());
     TreeNode<int>* newroot=prev;
  while (1) {
    TreeNode<int> *node = new TreeNode<int>(iterator.next());
    if (node->data == -1) {
      prev->right = NULL;
      return newroot;
    } else {
      prev->right = node;
      prev = node;
    }
  }
}
