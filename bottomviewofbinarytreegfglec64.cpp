vector <int> bottomView(Node *root) {
        vector<int> ans;
        map<int,int> mp; // will only store one value for each key as the second value is int not vector<int>
        queue<pair<int,Node*>> q;
        q.push(make_pair(0,root));
        while(!q.empty())
        {
            Node* temp=q.front().second;
            int vlevel=q.front().first;
            q.pop();
            mp[vlevel]=temp->data;
            if(temp->left) q.push(make_pair(vlevel-1,temp->left));
            if(temp->right) q.push(make_pair(vlevel+1,temp->right));
        }
        for (auto i : mp) {
        ans.push_back(i.second);
    }
        return ans;
    }