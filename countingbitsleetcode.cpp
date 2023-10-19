// Approach 1 which is the best approach with TC=O(n)
// dp approach with even,odd case
//Very concise and insightful solution, and here I am gonna simply explain why this formula works.

// When it comes to even numbers, i.e, 2,4,6,8, their binary should be like '10', '100', '110', '1000' so one notable difference is their unit digit is always 0, which means when you call >> 1- shift one bit rightwards and also means dividing by 2- would cause no change to the count of '1' in the binary string.

// Vice versa, when you meet odd numbers, shifting one bit rightwards always eliminates one '1' digit from original binary string, that is why we should "compensate" one '1' character to the count.

// To sum up, when you meet even number the count of '1's is always the same as its half number, on the other hand, remember to plus one to the odds' half number. or bit-1
// class Solution {
// public:
//     vector<int> countBits(int n) {
//         if(n==0) return {0};
//         vector<int> ans(n+1);
//         ans[0]=0;
//         ans[1]=1;
//         for(int bit=2;bit<=n;bit++)
//         {
//             if(bit&1) ans[bit]=ans[bit-1]+1;
//             else ans[bit]=ans[bit/2];
//         }
//         return ans;
//     }
// };
// normal brute force
// approach 2
// every integer has logn bits so the TC here becomes O(nlogn) in all cases as we iterate over all the bits
// class Solution {
// public:
//     vector<int> countBits(int n) {
//         vector<int> ans(n+1,0);
//         for(int i=0;i<=n;i++)
//         {
//             int cnt=0;
//             for(int j=0;j<32;j++)
//             {
//                 int bit=1<<j;
//                 if(bit&i)
//                 {
//                    cnt++;
//                 }
//             }
//             ans[i]=cnt;
//         }
//         return ans;
//     }
// };
// approach 3 which is better than approach 2 
// O(nlogn) 
// class Solution {
// public:
//     vector<int> countBits(int n) {
//        vector<int> ans(n+1);
//        for(int i=0;i<=n;i++)
//        {
//            int cnt=0;
//            int number=i;
//            while(number)
//            {
//               cnt+=(number&1);
//               number=(number>>1);
//            }
//            ans[i]=cnt;
//        }
//        return ans;
//     }
// };
// Brian Kernighan algo
// in this algo, we iterate over only set bits but in the worst case all the bits might be set so the worst case is O(n*logn) too
// when we subtract 1 from any number then the rightmost set bit becomes unset and all the bits to the right of that bit are flipped.
// here we dont want that flip so we do & with n-1
// if you dont understand then refer to this https://www.youtube.com/watch?v=KJnhAUkxAho
class Solution {
public:
    vector<int> countBits(int n) {
       vector<int> ans(n+1);
       ans[0]=0;
       for(int i=1;i<=n;i++)
       {
           int cnt=0;
           int number=i;
           while(number)
           {
               number=(number&(number-1));
               cnt++;
           }
           ans[i]=cnt;
       }
       return ans;
    }
};