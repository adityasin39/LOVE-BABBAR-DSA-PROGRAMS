// if you dont understand then refer to the editorial
// binary search approach
class Solution {
public:
    int search(int index, vector<int>& temp, int maxi)
    {
        int start=index;
        int end=temp.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(temp[mid]==maxi) return (mid-index+1); 
            if(temp[mid]<maxi) start=mid+1;
            else end=mid-1;
        }
        return (start-index);
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        set<int> st(nums.begin(),nums.end());
        vector<int> temp;
        while(st.size()>0)
        {
            auto it=st.begin();
            temp.push_back(*it);
            st.erase(st.begin());
        }
        int ans=INT_MAX;
        for(int i=0;i<temp.size();i++)
        {
            int mini=temp[i];
            int maxi=temp[i]+n-1;
            int maxiIdx=search(i,temp,maxi);
            int operations=n-maxiIdx;
            ans=min(ans,operations);
        }
        return ans;
    }
};
// sliding window 
// this is better than the binary search approach
// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         int n = nums.size();
//         int ans = n;
        
//         // std::set automatically sorts
//         set<int> unique(nums.begin(), nums.end());
//         vector<int> newNums;
//         for (int num : unique) {
//             newNums.push_back(num);
//         }
        
//         int j = 0;
//         for (int i = 0; i < newNums.size(); i++) {
//             while (j < newNums.size() && newNums[j] < newNums[i] + n) {
//                 j++;
//             }
            
//             int count = j - i;
//             ans = min(ans, n - count);
//         }
        
//         return ans;
//     }
// };