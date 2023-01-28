// the first and the second approaches are the best approaches available on internet.
//1st approach.
//in this method we will use the elements as a reference to the other element using them as an index number ...
//this method below is floyd's hare and tortoise method (cycle detection)

//initialize i as a slow pointer and j as fast pointer, due to a number coming twice it will make a cycle 
// the slow and fast pointer will meet at a certain point  , now re-initialize one of the pointers at the start and move both pointers by one step 
// now when the pointers meet that point is the repeating numbers.
// This approach is called the floyd hare tortoise method. In this method , we take two pointers one is slow and the other is fast.
// slow pointer moves by 1 whereas fast moves by 2 . initially both are kept at first element of the array. Then  after moving
// when they meet for the first time then either of them is set to the first element once again. Actually we get a cycle and this method is 
// also called cycle detection method. this time both the pointers are moved by 1 and when they meet then it is guaranteed that the meeting point
// will be the duplicate element. in case u dont understand the explanation, go to strivers video solution of this question.
// time complexity of this approach is O(n) and space is O(1).
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        do// i have used do while here instead of while because initially both pointers have the same value hence the conditon of the while loop would get false in the first iteratiio itself.

        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
//2nd approach.

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v(nums.size()+1,0);// 0 se initialize karna tha count ko hence ye kiya .
        for(auto it:nums)
        {
            v[it]++;
            if(v[it]>1) return it;
        }
        return 0;
    }
};

//3rd
//brute force. TLE maar diya.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i,j;
        for(i=0;i<nums.size();i++)
        {
            for(j=0;j<nums.size();j++)
            {
                if(nums[j]==nums[i] && i!=j) return nums[i];
            }
        }
        return 0;
    }
    
};
// 4th
//TLE maar diya isme bhi.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i,j;
        for(i=0;i<nums.size();i++)
        {
            for(j=i+1;j<nums.size();j++)
            if(nums[i]^nums[j]) continue;
            else
            return nums[i];
        }
        return 0;
    }
};
//5th
//ISME BHI TLE MAAR DIYA EK LOOP HONE KE BAAVJOOD MATLAB YE QUESTION 1st two approaches or STl wale approaches se solve hoga.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
     while(i<j)
     {
           if(nums[i]==nums[j]) return nums[i];
     }   
     return 0;
    }
};
//  6th
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++)v.push_back(nums[i]);
        
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
    if(v[i]==v[i+1]) return v[i];
        return 0;
    }
};
// 7th
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        for(auto it: m)
        {
            if(m[it.first]>1)return it.first;
        }
        return 0;
    }
};
// 8th
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int> st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(st.count(nums[i])) return nums[i];
            st.insert(nums[i]);
        }
        return 0;
    }
};