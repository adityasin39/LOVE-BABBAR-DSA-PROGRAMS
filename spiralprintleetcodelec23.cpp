// TC is O(n*m)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> ans;
      int noofrows=matrix.size();
      int noofcols=matrix[0].size();
      int cnt=0;
      int total=noofrows*noofcols;
      int startingrow=0;
      int endingrow=noofrows-1;
      int startingcol=0;
      int endingcol=noofcols-1;
      while(cnt<total)
      {
          for(int i=startingcol;cnt< total && i<=endingcol;i++) // cnt<total likha hai taaki waapas same repeat naa ho         
          {
              ans.push_back(matrix[startingrow][i]);
              cnt++;
          }
          startingrow++;
           for(int i=startingrow;cnt< total && i<=endingrow;i++)
          {
              ans.push_back(matrix[i][endingcol]);
              cnt++;
          }
                endingcol--;
           for(int i=endingcol;cnt< total && i>=startingcol;i--)
          {
              ans.push_back(matrix[endingrow][i]);
              cnt++;
          }
           endingrow--;
           for(int i=endingrow;cnt< total && i>=startingrow;i--)
          {
              ans.push_back(matrix[i][startingcol]);
              cnt++;
          }
          startingcol++;
      } 
      return ans;
      
    }
};