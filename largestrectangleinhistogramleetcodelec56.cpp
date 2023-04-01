// brute force which is better than other brute force available as this gets accepted
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int n=heights.size();
//         int leftsmaller[n];
//         int rightsmaller[n];
//         rightsmaller[n-1]=n;
//         for(int i=n-2;i>=0;i--)
//         {
//            int j=i+1;
//           while(j<n && heights[i]<=heights[j]) j=rightsmaller[j]; // skipping jumps
//           rightsmaller[i]=j;
//         }
//         leftsmaller[0]=-1;
//         for(int i=1;i<n;i++)
//         {
//            int j=i-1;
//           while(j>=0 && heights[i]<=heights[j]) j=leftsmaller[j]; // skipping jumps
//           leftsmaller[i]=j;
//         }
//         int maxarea=INT_MIN;
//         for(int i=0;i<n;i++)
//         {
//             int area=heights[i]*(rightsmaller[i]-leftsmaller[i]-1);
//             cout<<area<<" ";
//             if(area>maxarea) maxarea=area;
//         }
//         return maxarea;
//     }
// };
// stack approach refer to love babbar if you dont understand
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
};