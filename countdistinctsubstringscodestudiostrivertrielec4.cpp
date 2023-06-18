//TC=O(n^2) and SC is unpredictable as it will be like 26X26...
//we are inserting all possible substrings in the trie.
//brute force: get all substrings and put them in the set. TC=O(n^2) and SC=total number of substrings
// will be n^2 and average length of each string will be n/2 so overall SC=O(n^3);
struct Node
{
    Node* links[26];
    Node()
    {
        for( int i=0; i<26; i++ ) links[i]=NULL;
    }
    bool containskey(char ch)
    {
        if(links[ch-'a']) return true;
        return false;
    }
    void addkey(char ch, Node *newnode) { links[ch - 'a'] = newnode; }
    Node* nexttrie(char ch)
    {
        return links[ch-'a'];
    }
};

 int countDistinctSubstrings(string &s)
    {
        Node* root=new Node();
        Node* temp=root;
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=i;j<s.size();j++)
            {
                if(!temp->containskey(s[j]))
                {
                    temp->addkey(s[j], new Node());
                    cnt++;
                }
                temp=temp->nexttrie(s[j]);
            }
            temp=root;// to start over for next i
        }
        return cnt+1;
    }
