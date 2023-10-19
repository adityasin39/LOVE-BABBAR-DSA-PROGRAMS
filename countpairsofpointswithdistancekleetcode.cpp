//if you dont understand then refer to tech talk video
// if you use a map<pair<int,int>,int> mp then you will get tle in the last test case so its better to use a unordered map by changing the way of hashing and using a hash function
class Solution {
public:
    int countPairs(vector<vector<int>>& c, int k) {
        unordered_map<long long,long long> mp;
        int n=c.size();
        int ans=0;
        for(int i=0 ; i<n ; i++){
            for(int val=0 ; val<=k ; val++){
                long long x=val^c[i][0];    
                long long y=(k-val)^c[i][1];
                long long inner_key=x*1000001+y;
                if(mp.count(inner_key)){
                    ans+=mp[inner_key];
                }
            }
            long long outer_key=(long long)c[i][0]*(long long)1000001+(long long)c[i][1];
            mp[outer_key]++;
        }
        return ans;
    }
};