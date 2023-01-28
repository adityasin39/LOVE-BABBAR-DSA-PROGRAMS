class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;
        return fib(n-1)+fib(n-2);
        // loop wala soln
    //     int a=0;
    //     int b=1;
    //     int c;
    //     if(n==0 || n==1) return n;
    //     for(int i=2;i<=n;i++)
    //         {
    //          c=a+b;
    //         a=b;
    //         b=c;
    //         }
    //     return c;
    // }

    } 
};