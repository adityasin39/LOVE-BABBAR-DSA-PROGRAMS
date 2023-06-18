/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
// Approach 1
void preorder(BinaryTreeNode<int>* root, int& cnt)
{
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) cnt++;
    preorder(root->left, cnt);
    preorder(root->right,cnt);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int cnt=0;
    preorder(root, cnt);
    return cnt;
}
// Approach 2
// void inorder(BinaryTreeNode<int>* root, int& cnt)
// {
//     if(root==NULL) return;
//     inorder(root->left,cnt);
//     if(root->left==NULL && root->right==NULL) cnt++;
//     inorder(root->right,cnt);
// }
// int noOfLeafNodes(BinaryTreeNode<int> *root){
//     int cnt=0;
//     inorder(root,cnt);
//     return cnt;
// }
// Approach 3
// int noOfLeafNodes(BinaryTreeNode<int> *root){
//     queue<BinaryTreeNode<int>*> q;
//     q.push(root);
//     int cnt=0;
//     while(!q.empty())
//     {
//         BinaryTreeNode<int>* temp=q.front();
//         q.pop();
//         if(temp->left==NULL && temp->right==NULL) cnt++;
//         if(temp->left) q.push(temp->left);
//         if(temp->right) q.push(temp->right);
//     }
//     return cnt;
// }