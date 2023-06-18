 vector<int> topView(Node *root)
    {
        vector<int> ans;
        map<int,map<int,vector<int>>> mp;
        queue<pair<pair<int,int>,Node*>> q;
        q.push(make_pair(make_pair(0,0),root));
        while(!q.empty())
        {
            Node* temp=q.front().second;
            int vlevel=q.front().first.first;
            int level=q.front().first.second;
            q.pop();
            if(mp.find(vlevel)==mp.end()) // only extra line from vertical level order traversal
            mp[vlevel][level].push_back(temp->data);
            if(temp->left) q.push(make_pair(make_pair(vlevel-1,level+1),temp->left));
            if(temp->right) q.push(make_pair(make_pair(vlevel+1,level+1),temp->right));
        }
     
     for(auto i: mp)
     {
         for(auto j:i.second)
         {
             for(auto k:j.second)
            
             ans.push_back(k);
         }
     }
        return ans;
    }

};