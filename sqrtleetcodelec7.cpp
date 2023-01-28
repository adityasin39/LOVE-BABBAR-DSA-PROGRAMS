//BINARY SEARCH SOLUTION WITH LESSER RUNTIME// class Solution {
// public:
//     int mySqrt(int x) {
//         int start=0;
//         int end=x;
//         long mid;
//         int ans;
//         while(start<=end)
//         {
//             mid=start+(end-start)/2;
//             if(mid*mid<=x)
//             {
//                 start=mid+1;
//                 ans=mid;
//             }
//             else
//             end=mid-1;
//         }
//         return ans;
//     }
// };
//LINEAR SEARCH SOLUTION 
class Solution
{
public:
int mySqrt(int x)
{
  long y=0;
  while(y*y<=x)
  {
      y++;
  }  
  return y-1;
} 
};