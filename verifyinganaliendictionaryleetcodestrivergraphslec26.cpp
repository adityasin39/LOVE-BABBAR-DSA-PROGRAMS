class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
     vector<int> hash(26,0);
     for(int i=0;i<order.size();i++)
     {
         hash[order[i]-'a']=i;
     }   
     int i=0;
     int j=1;
     while(j<words.size())
     {
         int k=0;
         int l=0;
         while(k<words[i].size() && l<words[j].size())
         {
            
             if((words[i][k]!=words[j][l]) && (hash[words[i][k]-'a'] > hash[words[j][l]-'a'])) return false;
             if(words[i][k]!=words[j][l]) break;
              if(k+1<words[i].size() && l+1==words[j].size() && words[i][k]==words[j][l]) return false; // this is for apple and app and this line has to come before k++,l++ for aa,a
             k++;
             l++;
            
             
         }
         i++;
         j++;
     }
     return true;
    }
};