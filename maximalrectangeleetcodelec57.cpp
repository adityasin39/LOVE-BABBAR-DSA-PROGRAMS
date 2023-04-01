// in this approach we use concept of largest rectange area in histogram by making currow as a histogram by taking each of the rows as the base for our histogram bars so we start with 0th row and then we go to 0+1 rows and then 0+1+2 rows and so on .if you dont understand then refer to https://www.youtube.com/watch?v=oaN9ibZKMpA
// TC=O(rows*cols) SC=O(cols)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int> leftsmaller;
        vector<int> rightsmaller;
        stack<int> st;
        // for rightsmaller array
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) rightsmaller.push_back(n);
            else rightsmaller.push_back(st.top());
            st.push(i);
         }
         while(!st.empty()) st.pop();
       // for leftsmaller array
       for(int i=0;i<n;i++)
        {
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) leftsmaller.push_back(-1);
            else leftsmaller.push_back(st.top());
            st.push(i);
         }
         reverse(rightsmaller.begin(),rightsmaller.end());
         
         int maxarea=0;
         for(int i=0;i<n;i++)
         {
             int area=(rightsmaller[i]-leftsmaller[i]-1)*heights[i];
             if(area>maxarea) maxarea=area;
         }
         return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> currow(matrix[0].size());
        for(int i=0;i<matrix[0].size();i++) currow[i]=matrix[0][i]-'0';
        int maxarea=largestRectangleArea(currow);
        for(int i=1;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
               if(matrix[i][j]=='1')
               {
                   currow[j]+=1;
               }
               else currow[j]=0;
            }
            int area= largestRectangleArea(currow);
            maxarea=max(area,maxarea);
        }
        return maxarea;
    }
};