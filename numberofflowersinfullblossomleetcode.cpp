class Solution {
public:
    int searchFirst(vector<int>& arr, int t)
    {
        int start=0;
        int end=arr.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]<=t) start=mid+1;
            else end=mid-1;
        }
        return start;
    }
     int searchSecond(vector<int>& arr, int t)
    {
        int start=0;
        int end=arr.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]<t) start=mid+1;
            else end=mid-1;
        }
        return start;
    }
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> starts;
        vector<int> ends;
        for(int i=0;i<flowers.size();i++)
        {
            starts.push_back(flowers[i][0]);
            ends.push_back(flowers[i][1]);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        vector<int> ans;
        for(int i=0;i<people.size();i++)
        {
            int blossom_started=searchFirst(starts,people[i]);
            int blossom_ended=searchSecond(ends,people[i]);
            ans.push_back(blossom_started-blossom_ended);
        }
        return ans;
    }
};