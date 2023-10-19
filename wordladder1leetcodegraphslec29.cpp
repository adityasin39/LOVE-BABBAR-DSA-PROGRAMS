class Solution {
public:
// TC=O(wordList.size()*wordlength*26)
// dont do dfs here as it will get a lot complicated.
//BFS guarantees that the first path found from the starting word to the target word is the shortest path. Since BFS explores all neighboring nodes at the current level before moving to the next level, it ensures that the shortest path is discovered before longer paths. On the other hand, DFS does not guarantee finding the shortest path, as it explores a single path as deeply as possible before backtracking.
//if you dont understand then refer to striver notes of this lec
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        int n=beginWord.size();
        while(!q.empty())
        {
            string word=q.front().first;
            int length=q.front().second;
            q.pop();
            if(word==endWord) return length;
            for(int i=0;i<n;i++)
            {
                string temp=word;
               for(char ch='a';ch<='z';ch++)
               {
                   temp[i]=ch;
                   if(st.find(temp)!=st.end())
                   {
                       q.push({temp,length+1});
                       st.erase(temp);
                   }
               }
            }
        }
        return 0; // matlab endWord is not in the wordList
    }
};