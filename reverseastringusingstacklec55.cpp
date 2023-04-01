#include<iostream>
#include<stack>
using namespace std;
// TC=O(n) and SC=O(n) as stack takes up space
string reverse(string s)
{
   stack<char> st;
   for(int i=0;i<s.size();i++)
   {
    st.push(s[i]);
   }
   string ans="";
    while(st.empty()==0)// you cant use st.size() here as the stack size is changing after each pop
   {
       ans+=st.top();
       st.pop();
   }
   return ans;
}
int main(){
    string s;
    cout<<"Enter the string to be reversed"<<endl;
    cin>>s;
    string ans=reverse(s);
    cout<<"The reversed string is "<<ans<<endl;
    return 0;
}