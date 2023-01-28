// Approach 1
class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
         vector<int> count(26,0);
         for(auto it:str) count[it-'a']++;
             int maxi=0;
             char ch;
             for(int i=0;i<26;i++)
             {
                 if(maxi<count[i])
                 {
                     maxi=count[i];
                     ch=i+'a';
                 }
             }
         return ch;
    }

};
// Approach 2
// class Solution
// {
//     public:
//     //Function to find the maximum occurring character in a string.
//     char getMaxOccuringChar(string str)
//     {
//         map<char,int> count;
//         set<char> freq;
//         for(int i=0;i<str.size();i++) count[str[i]]++;
//         int maxi=(count.begin())->second;
//         for(auto it:count) maxi=max(maxi,it.second);
//         for(auto it: count) 
//         {
//             if(it.second==maxi) freq.insert(it.first);
//         }
//         return *(freq.begin());
        
//     }

// };