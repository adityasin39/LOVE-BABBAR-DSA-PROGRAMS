void createmapping(int in[], int n, unordered_map<int,int>& nodeToindex)// by reference hi karna hoga nahi toh solve function mein empty map chala jaaega
{
    for(int i=0;i<n;i++)
    {
        nodeToindex[in[i]]=i;
    }
}
    Node* solve(int in[],int post[], int n, int& index, int inorderstart, int inorderend,unordered_map<int,int>& nodeToindex) // pehle tle marega but by reference pass karne se unnecessary copying nahi hoga so it gets accepted
    {
        if(index<0 || inorderstart>inorderend) return NULL;
        int element=post[index];
        Node* root=new Node(element);
        int pos=nodeToindex[element];
        index--;
        root->right=solve(in,post,n,index,pos+1,inorderend,nodeToindex);// right call pehle maarna hoga
        root->left=solve(in,post,n,index,inorderstart,pos-1,nodeToindex);
        return root;
    }
Node *buildTree(int in[], int post[], int n) {
        int postorderindex=n-1;
        int inorderstart=0;
        int inorderend=n-1;
        unordered_map<int,int> nodeToindex;
        createmapping(in,n,nodeToindex);
        Node* ans=solve(in,post,n,postorderindex,inorderstart,inorderend,nodeToindex);
        return ans;
}
