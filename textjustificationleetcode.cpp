class Solution {
public:
    int findRight(int left, vector<string>& words, int maxWidth)
    {
        int right=left;
        int sum=words[right++].size();
        while(right<words.size() && ((sum+1+words[right].size())<=maxWidth))
        {
            sum+=1+words[right].size();
            right++;
        }
        return right-1;
    }
    string justify(int left, int right, vector<string>& words, int maxWidth)
    {
        bool isLastLine=false;
        if(right==words.size()-1) isLastLine=true;
        if(left==right)
        {
            string result="";
            result+=words[left];
            return result+padSpaces(result.size(),maxWidth);
        }
        else if(isLastLine)
        {
            string result="";
            for(int i=left;i<=right;i++)
            {
               result+=words[i]+" ";
            }
            result.pop_back();
            return result+padSpaces(result.size(),maxWidth);
        }
        else
        {
            int totalWordLength=0;
            for(int i=left;i<=right;i++)
            {
               totalWordLength+=words[i].size();
            }
            int numspaces=right-left;
            int totalSpaces=maxWidth-totalWordLength;
            int spaceperword=totalSpaces/numspaces;
            int remainder=totalSpaces%numspaces;
            string result="";
            string spacebetween="";
            while(spaceperword--) spacebetween+=" ";
            for(int i=left;i<=right;i++)
            {
               result+=words[i];
               if(i!=right) result+=spacebetween;
               result+=((remainder--)>0?" ":"");
            }
            return result+padSpaces(result.size(),maxWidth);
        }
    }
    string padSpaces(int length, int maxWidth)
    {
        string spaces="";
        int cnt=maxWidth-length;
        while(cnt--)
        {
            spaces+=" ";
        }
        return spaces;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int left=0;
        vector<string> ans;
        while(left<words.size())
        {
            int right=findRight(left,words,maxWidth);
            string line=justify(left,right,words,maxWidth);
            ans.push_back(line);
            left=right+1;
        }
        return ans;
    }
};