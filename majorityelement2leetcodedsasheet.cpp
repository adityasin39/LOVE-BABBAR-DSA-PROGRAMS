// moores voting algo
// we can have at max 2 majority elements.
// we just replicate majority elements 1 for two candidates
// to understand moores voting algo refer below
// There can be at most k - 1 major element in an array if the major element appears more than ⌊n / k⌋ times.

// In the begining, we assume there are k - 1 candidates:

// These candidates can take any value;
// The vote of these candidates must be 0
// Then we traverse the array:

// If current element equals to the value of any candidate, the candidate get a vote; (one voter can only vote for one candidate)
// If the vote of any candidate is 0, then current element is set as a new candidate and he can get a vote immediately; (A voter can also be elected)
// Otherwise, current element vote against all candidates and all candidates lose a vote.
// Assume you're voting for the president. If you want to select Trump or Biden. Ok, just vote for them (case 1). If Trump is impeached or Biden is dead, now you can run for the president (case 2). If you want to vote for Lebron James, of course both Biden or Trump won't get your vote (case 3).

// After election, we need to count the vote of each candidate to see whether they are qualified for the position, i.e., the vote is larger than ⌊n / k⌋.
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
     int n=nums.size();
     int candidate1=INT_MIN;
     int candidate2=INT_MIN;
     int votes1=0;
     int votes2=0;
     for(auto it: nums)
     {
         if(votes1==0 && it!=candidate2) // so that both candidates are not the same person. use this eg. [2,1,1,3,1,4,5,6] to understand
         {
             candidate1=it;
             votes1=1;
         }
         else if(votes2==0 && it!=candidate1)
         {
             candidate2=it;
             votes2=1;           
         }
         else if(it==candidate1) votes1++;
         else if(it==candidate2) votes2++;
         else 
         {
             votes1--;
             votes2--;
         }
     }
      int cnt1=0;
      int cnt2=0;
      for(auto it: nums)
      {
        if(it==candidate1) cnt1++;
        if(it==candidate2) cnt2++;
      }
      vector<int> ans;
      if(cnt1>n/3) ans.push_back(candidate1);
      if(cnt2>n/3) ans.push_back(candidate2);
      return ans;
    }
};
// bekar approach
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for(int i=0;i<nums.size();i++)
//         {
//             mp[nums[i]]++;
//         }
//         vector<int> ans;
//         for(auto it: mp){
//             if(it.second>nums.size()/3) ans.push_back(it.first);
//         }
//         return ans;
//     }
// };