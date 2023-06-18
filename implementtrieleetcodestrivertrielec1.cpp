// the reference node is also a trie and once the word is complete, we set the flag=true of the last reference trie.
struct Node
{
    // trie always has these two variables.
   Node* links[26];
   bool flag=false;
   bool containsletter(char ch)
   {
       if(links[ch-'a']) return true;
       return false;
   }
   void putletter(char ch, Node* refnode)
   {
      links[ch-'a']=refnode;
   }
   Node* nextNode(char ch)
   {
     return links[ch-'a'];
   }
   void setEnd()
   {
       flag=true;
   }
   bool isEnd()
   {
       if(flag==true) return true;
       return false;
   }
};
class Trie {
public:
  Node* root; //because every trie will have a root.
    Trie() {
        root=new Node(); // struct too has constructor.
    }
    
    void insert(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containsletter(word[i])) //if the letter doesnt exist
            {
              temp->putletter(word[i],new Node());
              temp=temp->nextNode(word[i]);
            }
            else // if the letter already exists
            {
             temp=temp->nextNode(word[i]); 
            }
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containsletter(word[i])) return false;
            temp=temp->nextNode(word[i]);
        }
        if(temp->isEnd()) return true;
        return false;

    }
    
    bool startsWith(string prefix) {
        Node* temp=root;
        for(int i=0;i<prefix.size();i++)
        {
            if(!temp->containsletter(prefix[i])) return false;
           temp=temp->nextNode(prefix[i]);
        }
         return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */