// TC=O(N*N) AND SC=O(N)
class Solution{
    public:
    int findPosition(int in[], int element,int inorderstart, int inorderend)
    {
        for(int i=inorderstart;i<=inorderend;i++) // for duplicate elements
        {
            if(in[i]==element) return i;
        }
    }
    Node* solve(int in[],int pre[], int n, int& index, int inorderstart, int inorderend)
    {
        if(index==n || inorderstart>inorderend) return NULL;
        int element=pre[index];
        Node* root=new Node(element);
        int pos=findPosition(in,element,inorderstart,inorderend); // this is done for duplicate elements
        index++;
        root->left=solve(in,pre,n,index,inorderstart,pos-1);
        root->right=solve(in,pre,n,index,pos+1,inorderend);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex=0;
        int inorderstart=0;
        int inorderend=n-1;
        Node* ans=solve(in,pre,n,preorderindex,inorderstart,inorderend);
        return ans;
    }
};