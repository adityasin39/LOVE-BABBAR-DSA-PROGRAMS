//one more approach: Count the no of set bits and if the no of set bits is 1 then it is a power of two.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0)return false;
        int ans=1;
        for(int i=0;i<=30;i++)
        {
               if(ans==n)
            {
                return true;
            }
            if(ans< INT_MAX/2)
            ans=ans*2;
         
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