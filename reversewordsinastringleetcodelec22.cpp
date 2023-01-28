// // we have three approaches for this question. The last approach is the best one.
// //Approach 1.
// // In this approach, space is O(n), so this is not in-place.
// //
// class Solution {
// public:
//     string reverseWords(string s) {
//         string ans="";
//         int n=s.length();
//         int i=n-1;
//         int j=i;
//         while(i>=0)
//         {
//             while( i>=0 && s[i]==' ')  i--;
//                 j=i;
//                 while( j>=0 && s[j]!=' ') j--;
              
//                if(ans.empty())ans= s.substr(j+1,i-j); // to avoid space before the final answer.
//                 else if(i>=0) ans+=" "+ s.substr(j+1,i-j);// i>=0 isliye kiya hai kyonki i<0 pe bhi kuch add ho jaaega jab ki string ka content khatam ho chuka hai.

//            i=j;
            
//         }
//         return ans;
//     }
// };
// // Approach 2.
// // In this approach, we have used the power of stringstream and stack.
// // stringstream takes in a stream and treats spaces as delimitor.So, due to stringstream, we ultimately get the words. To pass a single word >> operator is used.
// class Solution {
// public:
//     string reverseWords(string s) {
//         stringstream  ss(s);
//         string word;
//         string ans="";
//         stack<string> st;
//         while(ss>>word) st.push(word);
//         while(!st.empty())
//         {
//             ans+=st.top()+" ";
//             st.pop();

//         }
//         ans.pop_back(); //to remove the last extra space.
//         return ans;
        

//     }
// };
//Approach 3.
//this is an in-place approach.
class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        reverse(s.begin(),s.end());
        int l=0;
        int r=0;
        int i=0;
        while(i<n)
        {
            bool isWord=false;
          while(i<n && s[i]!=' ')
          {
              s[r]=s[i];
              r++;
              i++;
             isWord=true;
          }
          // s[i] must be ' '
          if(isWord)
          {
              reverse(s.begin()+l,s.begin()+r);
              s[r]=' ';
              r++;
              l=r;
          }
          // since s[i] is ' ' we need to pass it
          i++;
        }
        // postition of last character of string is r-2
        s.resize(r-1); // to remove the extra last space.
        return s;
    }
};