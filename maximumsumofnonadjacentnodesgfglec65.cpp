//Return a pair for each node in the binary tree such that the first of the pair indicates maximum sum when the data of a node is included and the second indicates maximum sum when the data of a particular node is not included. 
    pair<int,int> solve(Node* root)
    {
        if(root==NULL) return {0,0};
        pair<int,int> sum1=solve(root->left);
        pair<int,int> sum2=solve(root->right);
        pair<int,int> sum;
        sum.first=sum1.second+sum2.second+root->data;
        sum.second=max(sum1.first,sum1.second)+max(sum2.first,sum2.second);
        return sum;
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> ans=solve(root);
        return max(ans.first,ans.second);
    }
};