#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "abcdabghabd";
    string t = "ab#";
    int i = 0;
    int j = 0;
    int n = s.size();
    int m = t.size();
    vector<int> ans;
    while(i < n)
    {
        int index = i + 1;
        while(j < m && (t[j] == '#' || s[i] == t[j])) 
        {
            i++;
            j++;
        }
        if(j == m)
        {
            ans.push_back(index);
            i--;
            j = 0;
        }
        i++;
    }
    cout << "printing" << endl;
    for(auto it: ans) 
        cout << it << " ";
    return 0;
}
