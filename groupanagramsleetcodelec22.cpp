// agar nahi samajh aaye then refer to https://www.youtube.com/watch?v=vzdNOK2oB2E
//Here i have used two appproaches , both are great but the first one is simpler and better.
//Approach 1
//here we have used map and have taken the sorted string to be key and the anagrams are its values.
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         ios_base::sync_with_stdio(false);//to speed up the program
        cin.tie(NULL);
        unordered_map<string,vector<string>> m;// unordered to speed up the program
        for(int i=0;i<strs.size();i++)
        {
            string temp=strs[i];
            sort(strs[i].begin(),strs[i].end());
            m[strs[i]].push_back(temp);// aise bhi map values ko insert kar sakte hain
        }
          vector<vector<string>> res;
        for(auto it: m) res.push_back(it.second);
        return res;
    }
};
//Approach 2 
// we have used hash here as key.
// we cant use hash with unordered map
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
          ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        map<vector<int>,vector<string>> m;
        for(int i=0;i<strs.size();i++)
        {
            vector<int> count(26,0);
            int j=0;
            while(j<strs[i].size())
            {
                count[(strs[i]).at(j)-'a']++;
                j++;
            }
            m[count].push_back(strs[i]);
        }
        vector<vector<string>> res;
        for(auto it: m) res.push_back(it.second);
        return res;
    }
};