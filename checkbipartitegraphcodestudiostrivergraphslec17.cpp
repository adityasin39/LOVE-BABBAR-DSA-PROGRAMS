#include<bits/stdc++.h>
 bool check(vector<int>adj[], vector<int>& coloured,int startingNode)
    {
    
	    queue<int> q;
	    q.push(startingNode);
	    coloured[startingNode]=0;
	    while(!q.empty())
	    {
	        int size=q.size();
	        for(int i=0;i<size;i++)
	        {
	            int temp=q.front();
	            q.pop();
	            for(int j=0;j<adj[temp].size();j++)
	            {
	                if(coloured[adj[temp][j]]==-1)
	                {
	                    q.push(adj[temp][j]);
	                    coloured[adj[temp][j]]=!coloured[temp];
	                }
	                else if(coloured[adj[temp][j]]==coloured[temp]) return false;
	            }
	        }
	    }
	    return true;   
    }
bool isGraphBirpatite(vector<vector<int>> &edges) {
	vector<int> adj[edges.size()];
    for(int i=0;i<edges.size();i++)
	{
		for(int j=0;j<edges[0].size();j++)
		{
            if(edges[i][j]==1)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}
	int V=edges.size();
	 vector<int> coloured(V,-1);
	     for(int i=0;i<V;i++)
	     {
	         if(coloured[i]==-1)
	         {
	             if(check(adj,coloured,i)==false)
	             {
	                 return false;
	             }
	         }
	     }
	     return true;
}