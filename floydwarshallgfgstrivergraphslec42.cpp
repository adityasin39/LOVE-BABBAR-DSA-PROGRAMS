// TC=O(V^3) and SC=O(1)
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n=matrix.size();
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==-1)
	            {
	                matrix[i][j]=1e9; //we mark the impossible edges to be infinity first so that we can carry out our relaxation.
	            }
	            if(i==j)
	            {
	                matrix[i][j]=0; // initiliase the shortest distance of each possible source to 0
	            }
	        }
	    }
	    for(int k=0;k<n;k++)
	    {
	        for(int i=0;i<n;i++)
	        {
	            for(int j=0;j<n;j++)
	            {
					if(matrix[i][k]!=1e9 && matrix[k][j]!=1e9)
	                matrix[i][j]=min(matrix[i][j],(matrix[i][k]+matrix[k][j]));
	            }
	        }
	    }
	     for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            if(matrix[i][j]==1e9)
	            {
	                matrix[i][j]=-1; //waapas se -1 kar diya according to the question.
	            }
	        }
	    }
	    // to detect a negative weight cycle,
	   // for(int i=0;i<n;i++)
	   // {
	   //     if(matrix[i][i]<0) return true;
	   // }
	    
	}