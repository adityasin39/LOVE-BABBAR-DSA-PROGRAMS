// tle maar dega kyonki dp se solve hoga.
// recursion mein hamesha ek case ko solve karo baaki sab apne aap ho jaaega.
// f(n)= f(n-1)+f(n-2) matlab ki nth stair pe aane ke liye two ways hai one is one step wala i.e. f(n-1) and the other is two step wala i.e. f(n-2) so we get our recurrence relation.
class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2) return n;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};