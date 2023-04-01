// dry run for "23"
/*
output=a->> ad ->>a->> ae->>a->> af->>a->> b ->> bd and so on
*/
// if you still dont understand then refer to love babbar video
class Solution {
    private:
    void solve(string digits, string output, int index, vector<string>& ans, string mapping[])
    {
        if(index>=digits.size())
        {
            ans.push_back(output);
            return;
        }
        int number=digits[index]-'0';
        string letters=mapping[number]; // number ke corresponding letters nikal rahe hai
        for(int i=0;i<letters.size();i++) // loop lagaya hai because we want all characters of string letters
        {
            output.push_back(letters[i]);
            solve(digits,output,index+1,ans,mapping); // ek letter push karke dusre number se dusre letters ko nikal ne ke liye index+1 karke recursive call kiya
            output.pop_back();// this is backtracking matlab jaise ad ans mein store ho gaya toh we have to remove d to make ae and af so pop_back is doing backtracking
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        string output="";
        int index=0;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,output,index,ans,mapping);
        return ans;
    }
};