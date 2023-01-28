// in this question, i have compared l and r and as soon as the characters become unequal then we can ignore either of the charecters just be moving the pointers. here pair is used to return the new values of the two pointers.
pair<int,int> isPalindrome(string s, int start,int end)
{
   while(start<end){
            if(s[start]!=s[end]) break;
            start++;
            end--;
        }
        if(start>=end) return {-1,0};
     return {start,end};
}
class Solution {
public:
    bool validPalindrome(string s) {
        int l=0;
        int r=s.length()-1;
        pair<int,int> res;
       res= isPalindrome(s,l,r);
      if(res.first==-1) return true;
       int lt=res.first;
        int rt=res.second;
       res=isPalindrome(s,res.first+1,res.second);
        if(res.first==-1) return true;
        res=isPalindrome(s,lt,rt-1);
       if(res.first==-1) return true;
         return false;   
    }
};