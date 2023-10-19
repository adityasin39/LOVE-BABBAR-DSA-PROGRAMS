      //best 2 liner approach
        // if(n<=0) return false;
        // return (n&(n-1))==0;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return false;
        int ans=1;
               if(ans==n)
            {
                return true;
            }
        for(int i=1;i<=30;i++)
        {
            ans=ans*2;
                   if(ans==n)
            {
                return true;
            }
         
        }
        return false;
    }
};
// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n==0)return false;
//     while(n!=1)
//     {
//         int x=n%2;
//         if(x!=0)return false;

//         n=n/2;
//     }
//     return true;
//     }
// };