/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 // if you dont understand then refer to love babbar original video
class Solution {
public:
 TreeNode* createmapping(TreeNode* root, int target,unordered_map<TreeNode*,TreeNode*>& nodeToparent)
  {
      TreeNode* targetNode=NULL;
      queue<TreeNode*> q;
      q.push(root);
      nodeToparent[root]=NULL;
      while(!q.empty())
      {
          TreeNode* temp=q.front();
          q.pop();
          if(temp->val==target) targetNode=temp;
          if(temp->left)
          {
              q.push(temp->left);
              nodeToparent[temp->left]=temp;
          }
          if(temp->right)
          {
              q.push(temp->right);
              nodeToparent[temp->right]=temp;
          }
      }
      return targetNode;
  }
  void solve(TreeNode* root,int target, TreeNode* targetNode, unordered_map<TreeNode*,bool> visited,unordered_map<TreeNode*,TreeNode*>& nodeToparent, int& time)
  {
      queue<TreeNode*> q;
      q.push(targetNode);
      visited[targetNode]=true;
      while(!q.empty())
      {
          bool change=false;
          int size=q.size();
          for(int i=0;i<size;i++)
          {
          TreeNode* temp=q.front();
          q.pop();
          if(temp->left)
          {
              if(visited[temp->left]==false)
              {
                  q.push(temp->left);
                  visited[temp->left]=true;
                  change=true;
              }
          }
          if(temp->right)
          {
              if(visited[temp->right]==false)
              {
                  q.push(temp->right);
                  visited[temp->right]=true;
                  change=true;
              }
          }
          if(nodeToparent[temp])
          {
              if(visited[nodeToparent[temp]]==false)
              {
                  q.push(nodeToparent[temp]);
                  visited[nodeToparent[temp]]=true;
                  change=true;
              }
          }
          }
          if(change==true) time++;
      }
  }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> nodeToparent;
       TreeNode* targetNode= createmapping(root,start,nodeToparent);
        unordered_map<TreeNode*,bool> visited;
        int time=0;
        solve(root,start,targetNode,visited,nodeToparent,time);
        return time;
    }
};