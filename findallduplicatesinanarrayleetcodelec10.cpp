//In this question, i have used 3 approaches of which the first two are awesome and 3rd one is normal stl.
//1st
//this method is called negative marking method.
// in case you dont understand the soln then check out knowledge centers soln of this question.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            int k=abs(nums[i]);
            nums[k-1]=-1*nums[k-1];
            if(nums[k-1]>0) v.push_back(k); 
        


        }
        return v;
    }
};
//2nd
//Firstly, we put each element x in nums[x - 1]. Since x ranges from 1 to N, then x - 1 ranges from 0 to N - 1, it won't exceed the bound of the array.
//Secondly, we check through the array. If a number x doesn't present in nums[x - 1], then x is absent
//"Firstly, we put each element x in nums[x - 1]" : This is done using a simple loop where in we swap nums[i] with nums[nums[i]-1] until they become equal. The point to note here is that only when they become equal we increment i.

//"we check through the array. If a number x doesn't present in nums[x - 1], then x is absent." and nums[x-1] is a duplicate value so we add it to the res vector.

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]!=nums[nums[i]-1]) swap(nums[i],nums[nums[i]-1]);// in this line, basically we are trying to bring the value below the index which is less than the value.
            else
            i++;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=i+1) v.push_back(nums[i]); 
        }
        return v;
    }
};
//3rd
//normal stl brute force.
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(nums[i]);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]==v[i+1]) ans.push_back(v[i]);
        }
        return ans;

            }
};

