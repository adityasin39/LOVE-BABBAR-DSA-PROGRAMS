class Solution {
public:
    string reorganizeString(string s) {
        //Approach 1 which is the best approach for this problem. TC=O(n) and SC=O(1)
        // First place the most frequent element at even positions and then continue placing the other elements in even positions untill you reach at the end and then start over and fill the odd positions. In this way you ensure that no char is repeated.
        vector<int> hash(26,0);
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a']++;
        }
        int mostfreq=0;
        int element=0;
        for(int i=0;i<26;i++)
        {
            if(mostfreq<hash[i])
            {
                mostfreq=hash[i];
                element=i;
            }
        }
        if(mostfreq> (s.size()+1)/2) return "";
        int idx=0;
        vector<char> res(s.size());
        while(hash[element])
        {
           res[idx]=char(element+'a');
           idx+=2;
           hash[element]--;
        }
        for(int i=0;i<26;i++)
        {
            while(hash[i])
            {
                if(idx>=s.size())
                {
                    idx=1;
                }
                res[idx]=char(i+'a');
                idx+=2;
                hash[i]--;
            }
        }
        string ans="";
        for(int i=0;i<res.size();i++)
        {
            ans+=res[i];
        }
        return ans;
    // Approach 2.This is a heap appraoch where we make a max heap according to the frequency of the elements and then pop the most frequent element from the top and then check if the previous character inserted is the same, if it is then we pop another top element and insert that as well as the repeated char in the pq.If at any moment we have repeated char and then we pop another top element and if there is no top element then there is no possible answer.
    //Tc=O(nlogk) and SC=k
    //     priority_queue<pair<int,char>> pq;
    //     vector<int> freq(26,0);
    //     string ans="";
    //     for(int i=0;i<s.size();i++)
    //   {
    //      freq[s[i]-'a']++;
    //   }
    //   for(int i=0;i<26;i++)
    //   {
    //       if(freq[i]>0){
    //           char ch='a'+i;
    //       pq.push({freq[i],ch});
    //       }
    //   }
      
    //   while(!pq.empty())
    //   {
    //       pair<int,char> topele=pq.top();
    //       if(ans.size()>0 && topele.second==ans.back())
    //       {
    //           pq.pop();
    //           if(!pq.empty()){
    //           pair<int,char> newtop=pq.top();
    //           ans+=newtop.second;
    //           pq.pop();
    //           newtop.first--;
    //           if(newtop.first>0) pq.push(newtop);
    //           pq.push(topele);
    //           }
    //           else return "";
    //       }
    //       else{
    //       ans+=topele.second;
    //       pq.pop();
    //       topele.first--;
    //       if(topele.first>0)
    //       pq.push(topele);
    //       }
    //   }
    //   return ans;
    }
};