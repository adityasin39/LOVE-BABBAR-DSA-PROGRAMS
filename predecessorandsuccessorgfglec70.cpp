void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{

    if(root==NULL)
	{
		pre=NULL;
		suc=NULL;
		return;
	}
  Node* temp=root;
   pre=NULL;
   suc=NULL;
  while( temp!=NULL && temp->key!=key)
  {
    if (temp->key > key) {
        suc = temp;
      temp = temp->left;
      
    } else {
         pre=temp;
      temp = temp->right;
     
    }
  }
 if(temp==NULL) return;
  Node* temp1=temp->left;
  while(temp1!=NULL && temp1->right)
  {
      temp1=temp1->right;
  }
  if(temp1) pre=temp1;
  Node* temp2=temp->right;
  while(temp2!=NULL && temp2->left)
  {
      temp2=temp2->left;
  }
  if(temp2) suc=temp2;
