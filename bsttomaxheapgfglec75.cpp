//as it is a complete binary tree already so we dont have to change the structure we just need to change the values.
// According to the conditions, N>L and N>R and also L<R so combining the conditions we get L<R<N which means that if we get the inorder traversal which is sorted and then do postorder traversal then we will get our desired output.
//in case of min heap, we do preorder traversal.
class Solution{
  public:
  void inorder(Node* root, vector<int>& in)
  {
      if(root==NULL) return;
      inorder(root->left,in);
      in.push_back(root->data);
      inorder(root->right,in);
  }
  void postorder(Node* root, vector<int>& in, int& index)
  {
      if(root==NULL) return;
      postorder(root->left,in,index);
      postorder(root->right,in,index);
      root->data=in[index++];
  }
    void convertToMaxHeapUtil(Node* root)
    {
        vector<int> in;
        inorder(root,in);
        int index=0;
        postorder(root,in,index);
        
    }    
};