// Approach 1 - without stack best approach TC=O(n) and SC=O(1)
class Solution {
public:
    int minSwaps(string s) {
        int stacksize=0;
         for(int i=0;i<s.size();i++)
        {
               if(s[i]=='[')
            {
                stacksize++;
            }
            else
            {
                if(stacksize>0)
                {
                    stacksize--;
                }
            
            }
        }
        return ceil(double(stacksize)/2);
    }
};
// Approach 2 - with stack TC=O(n) and SC=O(n)
// class Solution {
// public:
//     int minSwaps(string s) {
//         stack<char> st;
//         for(int i=0;i<s.size();i++)
//         {
//                if(s[i]=='[')
//             {
//                 st.push(s[i]);
//             }
//             else
//             {
//                 if(s[i]==']' && st.empty()==0 && st.top()=='[')
//                 {
//                     st.pop();
//                 }
//                 else st.push(s[i]);
//             }
//         }
//         if(st.empty()) return 0;
//         cout<<"hello"<<endl;
//         int a=0;
//           while(st.empty()==0)
//         {
//           if(st.top()=='[') a++;
//           st.pop();
//         }
//         if(a&1) return a/2+1;
//         else return a/2;
//     }
// };