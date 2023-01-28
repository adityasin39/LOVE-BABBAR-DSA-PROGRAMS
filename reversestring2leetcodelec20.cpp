// 1st approach.
// class Solution {
// public:
//     string reverseStr(string s, int k) {
//         if(k==1) return s;
//          int n=s.size();
//         int i=0;
//         while(i<n)
//         {
//             if(n-i<=k) reverse(s.begin()+i,s.end());
//             else reverse(s.begin()+i,s.begin()+k+i);
//             i+=2*k;
//         }
//         return s;
//     }
// };
// 2nd approach.
// if you dont understand then refer https://www.youtube.com/watch?v=SUrrSVfk7pk
class Solution {
public:
    string reverseStr(string s, int k) {
        int l=0;
        int r=min((int)s.size(),k);// int se typecast isliye kiya kyonki k int hai aur size hamesha positive hoti hai toh unsigned long hai.
        while(l<s.size())
        {
            reverse(s.begin()+l,s.begin()+r);
            l+=2*k;
            r=min((int)s.size(),l+k);
        }
        return s;
    }
};