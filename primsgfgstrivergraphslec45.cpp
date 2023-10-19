// if the question would have asked for sum only then you dont need parent as well as the mst array.
	// TC=O(E*logE) + O(E*logE)~ O(E*logE), where E = no. of given edges.
//The maximum size of the priority queue can be E so after at most E iterations the priority queue will be empty and the loop will end. Inside the loop, there is a pop operation that will take logE time. This will result in the first O(E*logE) time complexity. Now, inside that loop, for every node, we need to traverse all its adjacent nodes where the number of nodes can be at most E. If we find any node unvisited, we will perform a push operation and for that, we need a logE time complexity. So this will result in the second O(E*logE).
    // SC=O(E)+O(V)+O(V-1). O(V-1) is for the mst because in the mst there are V nodes and V-1 edges.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<int> visited(V,0);
        pq.push({0,{0,-1}});
        int sum=0;
        vector<vector<int>> mst;
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int node=pq.top().second.first;
            int parent=pq.top().second.second;
            pq.pop();
            if(parent==-1)
            {
                visited[node]=1;
            }
            else if(!visited[node])
            {
                visited[node]=1;
                sum+=wt;
                vector<int> edge={node,parent};
                mst.push_back(edge);
            }
            else continue; // if the node is already visited.
            for(auto it: adj[node])
                {
                    int wt=it[1];
                    int neighbour=it[0];
                    if(!visited[neighbour])
                    {
                        pq.push({wt,{neighbour,node}});
                    }
                }
        }
        return sum;
    }
};