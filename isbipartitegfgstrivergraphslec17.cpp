//in the case of a disconnected graph, if each component is a bipartite graph then we can say that the whole grapht is a bipartite graph.
//A bipartite graph is a type of graph where the vertices can be divided into two distinct groups or sets in such a way that all edges of the graph connect vertices from different sets. In simpler terms, it is a graph where we can separate all the vertices into two groups in such a way that there are no edges connecting vertices within the same group.
// we will do bfs normally and whenever we encounter any uncoloured vertex then we will color it the opposite but as soon as we get a coloured adjacent edge which has the same color as the one which was just popped out of the queue then it means that two adjacent nodes have the same color resulting in false.
// TC=O(V+2E) and SC=O(V)
//using dfs
class Solution {
    private:
    bool check(vector<int>adj[], vector<int>& coloured,int startingNode,int previouscolor)
    {
        
       for(int i=0;i<adj[startingNode].size();i++)
       {
           if(coloured[adj[startingNode][i]]==-1) 
           {
               coloured[adj[startingNode][i]]=!previouscolor;
               if(check(adj,coloured,adj[startingNode][i],coloured[adj[startingNode][i]])==false) return false;
           }
           else if(coloured[adj[startingNode][i]]==coloured[startingNode]) return false;
       }
	 return true;   
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	     vector<int> coloured(V,-1);
	     for(int i=0;i<V;i++)
	     {
	         if(coloured[i]==-1)
	         {
	             coloured[i]=0;
	             if(check(adj,coloured,i,0)==false)
	             {
	                 return false;
	             }
	         }
	     }
	     return true;
	}

};
// class Solution {
//     private:
//     bool check(vector<int>adj[], vector<int>& coloured,int startingNode)
//     {
    
// 	    queue<int> q;
// 	    q.push(startingNode);
// 	    coloured[startingNode]=0;
// 	    while(!q.empty())
// 	    {
// 	        int size=q.size();
// 	        for(int i=0;i<size;i++)
// 	        {
// 	            int temp=q.front();
// 	            q.pop();
// 	            for(int j=0;j<adj[temp].size();j++)
// 	            {
// 	                if(coloured[adj[temp][j]]==-1)
// 	                {
// 	                    q.push(adj[temp][j]);
// 	                    coloured[adj[temp][j]]=!coloured[temp];
// 	                }
// 	                else if(coloured[adj[temp][j]]==coloured[temp]) return false;
// 	            }
// 	        }
// 	    }
// 	    return true;   
//     }
// public:
// 	bool isBipartite(int V, vector<int>adj[]){
// 	     vector<int> coloured(V,-1);
// 	     for(int i=0;i<V;i++)
// 	     {
// 	         if(coloured[i]==-1)
// 	         {
// 	             if(check(adj,coloured,i)==false)
// 	             {
// 	                 return false;
// 	             }
// 	         }
// 	     }
// 	     return true;
// 	}

// };