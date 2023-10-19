//if you want to find majority element in an array in an efficient way then you need to know about moores voting algorithm. The actual logic is explained in majority element 2
// in this case, we know that we can have only one majority element because the majority element has to occur more than n/2 times
// so we start looping from the start and we take two variables, one is candidate and the other is vote or count
// if the count is 0, we make that element the candidate and then whenever we encounter the same element as the candidate then we increase the count by 1.
// at the last we have to check if it actually has the majority.
// if you dont understand then refer to striver notes of this question
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=INT_MIN;
        int votes=0;
        for(auto it: nums)
        {
            if(votes==0) 
            {
                candidate=it;
                votes=1;
                continue;
            }
            if(it==candidate) votes++;
            else votes--;
        }
        int cnt=0;
        for(auto it: nums)
        {
            if(it==candidate) cnt++;
        }
        if(cnt>nums.size()/2) return candidate;
        return -1;
    }
};