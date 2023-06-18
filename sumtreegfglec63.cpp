public:
    int check(Node* root)
    {
        if(root==NULL) return 0;;
         if(root->left==NULL && root->right==NULL) return root->data;
         int leftsum=check(root->left);
         if(leftsum==-1) return -1;
         int rightsum=check(root->right);
         if(rightsum==-1) return -1;
         if(leftsum+rightsum!=root->data) return -1;
         return leftsum+rightsum+root->data;
    }
    bool isSumTree(Node* root)
    {
         if(check(root)==-1) return false;
         return true;
    }