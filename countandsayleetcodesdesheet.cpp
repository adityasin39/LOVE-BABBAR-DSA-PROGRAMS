class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string prev="1";
        for(int i=2;i<=n;i++)
        {
            string curr="";
            int j=0;
            while(j<prev.size()){
            int cnt=1;
            while(j+1<prev.size() && prev[j]==prev[j+1]){
                cnt++;
                j++;
            }
            curr+=to_string(cnt)+prev[j];
            j++;
            }
            prev=curr;
        }
        return prev;
    }
};