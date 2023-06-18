class Solution {
  public:
 
    bool isHeap(struct Node* tree) {
      queue<Node*> q;
        q.push(tree);
        bool end=false;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                Node* temp=q.front();
                q.pop();
                if(temp->left==NULL && temp->right!=NULL) return false;
                if(temp->left )
                { 
                    if(end==true)return false;
                    else 
                    {
                        if(temp->left->data>temp->data) return false;
                      else  q.push(temp->left);
                    }
                }
                if(temp->right)
                {
                    if(temp->right->data>temp->data) return false;
                    else q.push(temp->right);
                } 
                else end=true;
            }
        }
        return true;
    }
};