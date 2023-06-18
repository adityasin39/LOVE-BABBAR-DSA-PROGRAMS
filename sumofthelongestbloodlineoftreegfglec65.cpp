void solve(Node* root, int cursum, int curlevel, int& maxsum, int& maxlevel)
    {
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) 
        {
            cursum+=root->data;
            curlevel+=1;
            if(curlevel>maxlevel) 
            {
                maxsum=cursum;
                maxlevel=curlevel;
            }
            if(curlevel==maxlevel) maxsum=max(maxsum,cursum);
            return;
        }
        cursum+=root->data;
        curlevel+=1;
        solve(root->left,cursum,curlevel,maxsum,maxlevel);
        solve(root->right,cursum,curlevel,maxsum,maxlevel);
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        int cursum=0;
        int maxsum=INT_MIN;
        int maxlevel=INT_MIN;
        int curlevel=0;
        solve(root,cursum,curlevel,maxsum,maxlevel);
        return maxsum;
    }
};