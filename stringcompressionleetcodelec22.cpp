//Approach 1. 
class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int k=0;
        int n=chars.size();
    
        while(i<n)
        {
           int j=i+1;
            while(j<n && chars[j]==chars[i]) j++;
            
            chars[k++]=chars[i];
            if(j-i>1)
            {
             string temp=to_string(j-i);// to convert an int or float to string.
             for(int i=0;i<temp.size();i++) chars[k++]=temp[i];

            }
            i=j;
        }
        return k;
    }
};