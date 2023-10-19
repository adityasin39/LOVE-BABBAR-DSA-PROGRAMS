// Let n be the answer, the minimum number of times A has to be repeated.

// For B to be inside A, A has to be repeated sufficient times such that it is at least as long as B (or one more), hence we can conclude that the theoretical lower bound for the answer would be length of B / length of A.

// Let x be the theoretical lower bound, which is ceil(len(B)/len(A)).

// The answer n can only be x or x + 1 (in the case where len(B) is a multiple of len(A) like in A = "abcd" and B = "cdabcdab") and not more. Because if B is already in A * n, B is definitely in A * (n + 1).

// Hence we only need to check whether B in A * x or B in A * (x + 1), and if both are not possible return -1.
// A more general explanation is actually this: since we repeat A, so the substring that equals B after repeating A certain times must start at position: 0, 1, ..., len(A)-1. The reason is that, anything after that will be a repeat from these starting positions (you can also think this as a periodic function). Therefore, we need to guarantee that, starting from any of these positions, i.e., 0,1, ..., len(A) -1, the new string created from A must has a lenght of at least len(B). This is to say that, even if starting from position len(A)-1, we need to have the new string length at no less than len(B). This cannot be achieved by just repeat x times (suppose x is the minimum x such that len(A)*x >= len(B)). However, if we repeat (x+1) times, the length would be enough for position len(A) -1, and we don't need to further check with repeating (x+2) or more times.
//kmp approach
// if you dont understand then refer to https://www.youtube.com/watch?v=JoF0Z7nVSrA and gfg
class Solution{
    public:
    void longestprefixsuffix(vector<int>& lps, string& b, int n)
    {
        int len=0;
        int i=1;
        lps[0]=0;
        while(i<n)
        {
            if(b[i]==b[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lps[i]=0;
                    i++;
                }
                else len=lps[len-1];
            }
        }
    }
    bool kmp(string& s, string& b)
    {
        int m=s.size();
        int n=b.size();
        vector<int> lps(n,0);
        longestprefixsuffix(lps,b,n);
        int i=0;
        int j=0;
        while(i<m)
        {
            while(j<n && s[i]==b[j])
            {
                i++;
                j++;
            }
            if(j==n) return true;
            if(j==0) i++;
            else j=lps[j-1];
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int required=ceil(b.size()/(double)a.size());
        string s="";
        for(int i=0;i<required;i++)
        {
           s+=a;
        }
        if(kmp(s,b)) return required;
        s+=a;
        if(kmp(s,b)) return required+1;
        return -1;
    }
};
//rabin karp approach
// if you dont understand then refer to gfg article
#define d 29
#define q INT_MAX
#define ll long long
class Solution {
public:
    bool rabin_karp(string& s, string& b)
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
               if(j==n) return true;
           }
           if(i<m-n)
           {
               hash_txt=(d*(hash_txt-s[i]*h)+s[i+n])%q;
                if(hash_txt<0) hash_txt+=q;
           }
           i++;
       }
       return false;
    }
    int repeatedStringMatch(string a, string b) {
        int required=ceil(b.size()/(double)a.size());
        string s="";
        for(int i=0;i<required;i++)
        {
           s+=a;
        }
        if(rabin_karp(s,b)) return required;
        s+=a;
        if(rabin_karp(s,b)) return required+1;
        return -1;
    }
};
// string::find approach
    int repeatedStringMatch(string a, string b) {
        int required=ceil(b.size()/(double)a.size());
        string s="";
        for(int i=0;i<required;i++)
        {
           s+=a;
        }
        if(s.find(b)!=string::npos) return required;
        s+=a;
        if(s.find(b)!=string::npos) return required+1;
        return -1;
    }
};