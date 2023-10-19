class Solution {
public:
// kmp
    //     void longestprefixsuffix(vector<int>& lps, string& b, int n)
    // {
    //     int len=0;
    //     int i=1;
    //     lps[0]=0;
    //     while(i<n)
    //     {
    //         if(b[i]==b[len])
    //         {
    //             len++;
    //             lps[i]=len;
    //             i++;
    //         }
    //         else
    //         {
    //             if(len==0)
    //             {
    //                 lps[i]=0;
    //                 i++;
    //             }
    //             else len=lps[len-1];
    //         }
    //     }
    // }
    // int kmp(string& s, string& b)
    // {
    //     int m=s.size();
    //     int n=b.size();
    //     vector<int> lps(n,0);
    //     longestprefixsuffix(lps,b,n);
    //     int i=0;
    //     int j=0;
    //     while(i<m)
    //     {
    //         while(j<n && s[i]==b[j])
    //         {
    //             i++;
    //             j++;
    //         }
    //         if(j==n) return (i-n);
    //         if(j==0) i++;
    //         else j=lps[j-1];
    //     }
    //     return -1;
    // }
//     int strStr(string haystack, string needle) {
//         return kmp(haystack,needle);
//     }
// };
// rabin karp
#define d 29
#define q INT_MAX
#define ll long long
    int rabin_karp(string& s, string& b)
    {
       int m=s.size();
       int n=b.size();
       ll h=1;
       for(int i=0;i<n-1;i++) h=(ll)((h*d))%q;
       ll hash_txt=0;
       ll hash_pattern=0;
       for(int i=0;i<n;i++)
       {
           hash_txt=(hash_txt*d+s[i])%q;
           hash_pattern=(hash_pattern*d+b[i])%q;
       }
       int i=0;
       while(i<=m-n)
       {
           if(hash_txt==hash_pattern)
           {
               int j=0;
               while(j<n)
               {
                   if(s[i+j]!=b[j]) break;
                   j++;
               }
               if(j==n) return i;
           }
           if(i<m-n)
           {
               hash_txt=(d*(hash_txt-s[i]*h)+s[i+n])%q;
                if(hash_txt<0) hash_txt+=q;
           }
           i++;
       }
       return -1;
    }
   int strStr(string haystack, string needle) {
        return rabin_karp(haystack,needle);
    }
};