// here, i have listed down 3 great approaches.
// 1st approach.
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        int i=0;
        while(i<nums.size())
        {
           if(nums[i]!=nums[nums[i]-1]) swap(nums[i],nums[nums[i]-1]);
           else i++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1) v.push_back(i+1);
        }
        return v;
    }
};
// 2nd approach.
// The idea is very similar to problem 442. Find All Duplicates in an Array

// First iteration to negate values at position whose equal to values appear in array. Second iteration to collect all position whose value is positive, which are the missing values. Complexity is O(n) Time and O(1) space
// this is the same negative marking method but has some difference. The difference is that here we are not making already negative numbers positive.
//The indexes+1 corresponding to the numbers which are positive are the missing numbers. 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        for(int i=1;i<=nums.size();i++)
        {
            int k=abs(nums[i-1]);
        if(nums[k-1]>0) nums[k-1]=-1*nums[k-1];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0) v.push_back(i+1);
        }
        return v;
    }
};
// 3rd approach.
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v(nums.size()+1,0);
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            v[nums[i]]++;
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(v[i]==0) ans.push_back(i);
        }
        return ans;
    }
};