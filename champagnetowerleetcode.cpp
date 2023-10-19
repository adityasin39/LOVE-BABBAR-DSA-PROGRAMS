class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
       vector<double> currow(1,poured);
       for(int i=0;i<=query_row;i++)
       {
           vector<double> nextrow(i+2,0);
           for(int j=0;j<=i;j++)
           {
              if(currow[j]>1)
              {
                  nextrow[j]+=(currow[j]-1)/2.0;
                  nextrow[j+1]+=(currow[j]-1)/2.0;
                  currow[j]=1;
              }
           }
           if(i!=query_row) currow=nextrow;
       }   
       return currow[query_glass];
    }
};