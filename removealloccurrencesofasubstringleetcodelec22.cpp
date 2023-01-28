class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part)!=string::npos)// or while(s.lenth()!=0 && s.find(part)<s.length())
        s.erase(s.find(part),part.length());
        return s;    
    }
};