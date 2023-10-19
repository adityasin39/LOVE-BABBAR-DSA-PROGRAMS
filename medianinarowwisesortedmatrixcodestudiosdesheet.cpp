// if you dont understand then refer to striver video of this question
#include<bits/stdc++.h>
bool isPossible(int mid, vector<vector<int>>& matrix, int m, int n)
{
    int cnt=0;
    for(int i=0;i<m;i++)
    {
        if(mid>matrix[i][n-1]) cnt+=n;
        else if(mid<matrix[i][0]) cnt+=0;
        else
        {
            int s=0;
            int e=n-1;
            while(s<=e)
            {
                int midrow=s+(e-s)/2;
                if(matrix[i][midrow]<=mid) s=midrow+1;
                else e=midrow-1;
            }
            cnt+=s;
        }
    }
    if(cnt>=(m*n)/2+1) return true;
    return false;
}
int median(vector<vector<int>> &matrix, int m, int n) {
    int start=1;
    int end=1e9;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(mid,matrix,m,n))
        {
            end=mid-1;
        }
        else start=mid+1;
    }
    return start;
}