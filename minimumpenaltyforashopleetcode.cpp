class Solution {
public:
    int bestClosingTime(string customers) {
        // two pass, start from the right if you want to keep track of penalty
        // int n=customers.size();
        // int penalty=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(customers[i]=='N') penalty++;
        // }
        // int ans=n;
        // int mini=penalty;
        // for(int i=n-1;i>=0;i--)
        // {
        //     if(customers[i]=='Y') penalty++;
        //     else penalty--;
        //     if(penalty<=mini)
        //     {
        //         mini=penalty;
        //         ans=i;
        //     }
        // }
        // return ans;
        // single pass, start from the left if you want to keep track of gain instead of penalty
        int n=customers.size();
        int gain=0;
        int maxi=0;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            if(customers[i]=='Y') gain++;
            else gain--;
            if(gain>maxi)
            {
                maxi=gain;
                ans=i;
            }
        }
        return ans+1;
    }
};