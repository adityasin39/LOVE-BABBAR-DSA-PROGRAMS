vector<int> addleftboundary(Node* root,vector<int>& left)
  {
      if(root==NULL) return left;
      if(root->left==NULL && root->right==NULL) return left;
      left.push_back(root->data);
      left=addleftboundary(root->left,left);
      if(root->left==NULL && root->right!=NULL)
      left=addleftboundary(root->right,left);
      return left;
  }
  vector<int> addleaves(Node* root, vector<int>& leaf)
  {
      if(root==NULL) return leaf;
      if(root->left==NULL && root->right==NULL) 
      {
          leaf.push_back(root->data);
          return leaf;
      }
      leaf=addleaves(root->left,leaf);
      leaf=addleaves(root->right,leaf);
      return leaf;
  }
  vector<int> addrightboundary(Node* root, vector<int>& right)
  {
      if(root==NULL) return right;
      if(root->left==NULL && root->right==NULL) return right;
      right=addrightboundary(root->right,right);
      if(root->right==NULL && root->left!=NULL)
      right=addrightboundary(root->left,right);
      right.push_back(root->data);
      return right;
  }
    vector <int> boundary(Node *root)
    {
        vector<int> left;
        vector<int> leaf;
        vector<int> right;
        left= addleftboundary(root->left,left);
        leaf= addleaves(root,leaf);
        right= addrightboundary(root->right,right);
        vector<int> ans;
        if(root->left!=NULL || root->right!=NULL)
        ans.push_back(root->data);
        for(int i=0;i<left.size();i++)
        {
            ans.push_back(left[i]);
        }
         for(int i=0;i<leaf.size();i++)
        {
            ans.push_back(leaf[i]);
        }
         for(int i=0;i<right.size();i++)
        {
            ans.push_back(right[i]);
        }
        return ans;
    }
};
