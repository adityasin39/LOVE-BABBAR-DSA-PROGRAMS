// recursive
void left(Node* root,int level, vector<int>& ans)
{
    if(root==NULL) return;
    if(level==ans.size()) ans.push_back(root->data);
    left(root->left,level+1,ans);
    left(root->right,level+1,ans);
}
vector<int> leftView(Node *root)
{
    vector<int> ans;
    int level=0;
    left(root,level,ans);
    return ans;
}

// iterative approach
// vector<int> leftView(Node *root)
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
//       if(i==0) ans.push_back(temp->data);
//       if(temp->left) q.push(temp->left);
//       if(temp->right) q.push(temp->right);
//       }
//   }
//   return ans;
// }
