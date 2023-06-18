class Solution {
public:
   int lengthOfLongestSubstring(string s) {
       //best approach TC=O(n) and SC=O(n)
       //if you dont understand then refer to strivers website or video
      vector < int > mpp(256, -1);

      int left = 0, right = 0;
      int n = s.size();
      int len = 0;
      while (right < n) {
        if (mpp[s[right]] != -1)
          left = max(mpp[s[right]] + 1, left);

        mpp[s[right]] = right;

        len = max(len, right - left + 1);
        right++;
      }
      return len;
      // 2nd best approach TC=O(2n) and SC=O(n)
        // int n=s.size();
        // if(n==0) return 0;
        // int left=0;
        // int right=0;
        // unordered_set<char> st;
        // int longest=0;
        // while(right<n)
        // {
        //     if(st.find(s[right])!=st.end())
        //     {
        //     st.erase(s[left]);
        //     left++;
        //     }
        //     else{
        //     longest=max(longest,right-left+1);
        //     st.insert(s[right]);
        //     right++;
        //     }
        // }
        // return longest;
    }
};