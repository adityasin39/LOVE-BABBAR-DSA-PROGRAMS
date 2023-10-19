class Solution {
public:
    struct cmp{
      bool operator()(string s1, string s2){
          if(s1.size()>s2.size()) return false;
          else if(s2.size()>s1.size()) return true;
          else 
          {
              if(s1<s2) return true;
              return false;
          }
      }  
    };
    string add(string a, string b)
    {
        if(a.find(b)!=string::npos) return a; // this is imp
        if(b.find(a)!=string::npos) return b;
        string merged=a+b; // agar match nahi hua
        for(int i=min(a.size(),b.size());i>=0;i--)
        {
            if(a.substr(a.size()-i)==b.substr(0,i))
            {
                merged=a+b.substr(i);
                break;
            }
        }
        return merged;
    }
    string minimumString(string a, string b, string c) {
        string ans1=add(add(a,b),c);
        string ans2=add(add(b,a),c);
        string ans3=add(add(a,c),b);
        string ans4=add(add(c,a),b);
        string ans5=add(add(b,c),a);
        string ans6=add(add(c,b),a);
        vector<string> temp={ans1,ans2,ans3,ans4,ans5,ans6};
        sort(temp.begin(),temp.end(),cmp());
        return temp[0];
    }
};