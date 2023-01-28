class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
       int n=words.size();
       if(n==1) return words;
       int i=n-1;
       string tempo1=words[n-1];
       string tempo2=words[n-2];
       sort(tempo1.begin(),tempo1.end());
       sort(tempo2.begin(),tempo2.end());
       if(tempo1==tempo2) words.erase(words.end());
       int j=n-2;
       while(j>0)
       {
           string temp1=words[j];
           string temp2=words[j-1];
           sort(temp1.begin(),temp1.end());
           sort(temp2.begin(),temp2.end());
           if(temp1==temp2) words.erase(words.begin()+j);
           j--;
       } 
       return words;
    }
};