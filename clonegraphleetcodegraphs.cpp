/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// you need to understand two things.
//1. you need an unordered map to check whether clone is already created of the node and also to get the clone in O(1) time
// 2. you cant just do clone->neighbors=node->neighbors because you are copying the original nodes into the clone whereas clone->neighbors should have the cloned nodes not the original nodes.
// bfs
// class Solution {
// public:
//     Node* cloneGraph(Node* node) {
//         if(node==NULL) return NULL;
//         unordered_map<Node*,Node*> mp;
//         Node* parent=new Node(node->val);
//         mp[node]=parent;
//         queue<Node*> q;
//         q.push(node);
//         while(!q.empty())
//         {
//             Node* temp=q.front();
//             q.pop();
//             vector<Node*> neighbours;
//             for(auto it:temp->neighbors)
//             {
//                 if(mp.find(it)!=mp.end()) neighbours.push_back(mp[it]);
//                 else
//                 {
//                     Node* clone=new Node(it->val);
//                     mp[it]=clone;
//                     neighbours.push_back(mp[it]);
//                        q.push(it); 
//                 } 
//             }
//             mp[temp]->neighbors=neighbours;
//         }
//         return parent;
//     }
// };
// dfs
class Solution {
public:
    Node* dfs(Node* curr, unordered_map<Node*,Node*>& mp)
    {
        Node* clone=new Node(curr->val);
        mp[curr]=clone;
        vector<Node*> neighbours;
        for(auto it: curr->neighbors)
        {
            if(mp.find(it)!=mp.end()) neighbours.push_back(mp[it]);
            else neighbours.push_back(dfs(it,mp));
        }
        clone->neighbors=neighbours;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        unordered_map<Node*,Node*> mp;
        return dfs(node,mp);
    }
};