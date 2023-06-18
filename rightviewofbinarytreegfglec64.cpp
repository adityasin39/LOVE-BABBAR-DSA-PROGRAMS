class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void right(Node* root,int level, vector<int>& ans)
{
    if(root==NULL) return;
    if(level==ans.size()) ans.push_back(root->data);
    right(root->right,level+1,ans);
    right(root->left,level+1,ans);
}
vector<int> rightView(Node *root)
{
    vector<int> ans;
    int level=0;
    right(root,level,ans);
    return ans;
}
};
// iterative approach
// vector<int> rightView(Node *root)
// {
//     vector<int> ans;
//   if(root==NULL) return ans;
//   queue<Node*> q;
//   q.push(root);
//   while(!q.empty())
//   {
//       int size=q.size();
//       for(int i=0;i<size;i++)
//       {
//       Node* temp=q.front();
//       q.pop();
//       if(i==size-1) ans.push_back(temp->data);
//       if(temp->left) q.push(temp->left);
//       if(temp->right) q.push(temp->right);
//       }
//   }
//   return ans;
// }