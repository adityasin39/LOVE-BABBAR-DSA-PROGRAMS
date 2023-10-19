// three things that you need to get right
// use map instead of vector for dp table as dp table will waste a lot of space to accomodate last resulting in mle
// if(intervals[index][0]>last) then return otherwise iterations will increase a lot giving tle
// take max(last,intervals[index][1]) otherwise extra taps will be considered and will give wrong answer
class Solution {
public:
    long long solve(vector<vector<int>>& intervals, int n, int last, int index,map<pair<long long,long long>,long long>& m)
    {
         if(index>n && last<n) return INT_MAX;
        if(last>=n) return 0;
        if(intervals[index][0] > last)
        return INT_MAX;
        if(m.find({last,index})!=m.end())
        return m[{last,index}];
        long long take=1+(long long)(solve(intervals,n,max(intervals[index][1],last),index+1,m));
        long long nottake=solve(intervals,n,last,index+1,m);
        return m[{last,index}]=min(take,nottake);
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intervals;
        for(int i=0;i<ranges.size();i++)
        {
            int start=i-ranges[i];
            int end=i+ranges[i];
            vector<int> interval={start,end};
            intervals.push_back(interval);
        }
        map<pair<long long,long long>,long long> m;
        sort(intervals.begin(),intervals.end());
        long long ans=solve(intervals,n,0,0,m);
        if((int)ans==INT_MAX) return -1;
        return ans;
    }
};