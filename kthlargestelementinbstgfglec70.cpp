// we can do reverse inorder(right node left) traversal as it will give the nodes in decreasing order and then the same logic of kth smallest element can be applied
// Also we can do reverse morris traversal
class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
         int ans;
         Node* curr=root;
        while(curr!=NULL)
        {
            if(curr->right==NULL)
            {
                K--;
                if(K==0) ans= curr->data;
                curr=curr->left;
            }
            else
            {
                Node* prev=curr->right;
                while(prev->left!=NULL && prev->left!=curr)
                {
                    prev=prev->left;
                }
                if(prev->left==NULL)
                {
                    prev->left=curr;
                    curr=curr->right;
                }
                else
                {
                    prev->left=NULL;
                    K--;
                    if(K==0) ans= curr->data;
                    curr=curr->left;
                }
            }
        }
        return ans;
    }
};