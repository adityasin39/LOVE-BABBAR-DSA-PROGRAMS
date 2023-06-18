// this approach doesnt require extra vector space and thus is better
bool findancestor(Node* root, int& k, int node, bool& found, int& ans)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==node)
    {
        k--;
        return true;
    }
   bool left= findancestor(root->left,k,node,found,ans);
   if(left)
   {
       if(k==0)
       {
           ans=root->data;
           return false;
       }
       k--;
       return true;
   }
   bool right=findancestor(root->right,k,node,found,ans);
   if(right)
   {
       if(k==0)
       {
           ans=root->data;
           return false;
       }
       k--;
       return true;
   }
   return false;
}
int kthAncestor(Node *root, int k, int node)
{
   bool found=false;
   int ans=-1;
  bool res= findancestor(root,k,node,found,ans);
   return ans;
}
// 2nd approach
// void solve(Node* root,int node, vector<int>& ancestor, bool& found)
// {
//     if(root==NULL) return;
//     if(root->data!=node) 
//     {
//         ancestor.push_back(root->data);
//     }
//     else
//     {
//         found=true;
//         return;
//     }
//     solve(root->left,node,ancestor,found);
//     if(found==true) return;
//     solve(root->right,node,ancestor,found);
//     if(found==true) return;
//     ancestor.pop_back();
// }
// int kthAncestor(Node *root, int k, int node)
// {
//     vector<int> ancestor;
//     bool found=false;
//     solve(root,node,ancestor,found);
//     int size=ancestor.size();
//     if(size<k) return -1;
//     return ancestor[size-k];
// }