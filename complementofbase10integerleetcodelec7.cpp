        //agar bits level pe khelna hai toh bitwise operators and left shift, right shift mein se koi use hoga.
class Solution {
public:
    int bitwiseComplement(int n) {
        int m=n;
        if(n==0)return 1;
        int mask=0;
        while(m)
        {
            mask=mask<<1;
            mask=mask|1;
            
            m=m>>1;
        }
        int ans= ~(n)&mask;
        return ans;
    }
};