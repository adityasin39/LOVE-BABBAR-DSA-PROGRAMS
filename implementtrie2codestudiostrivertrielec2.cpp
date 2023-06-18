// end_with is used to maintain the count of words and cnt_prefix is increased in the reference trie.
#include <bits/stdc++.h> 
struct Node
{
   Node* links[26];
   int end_with=0;
   int cnt_prefix=0;
   bool containsletter(char ch)
   {
       if(links[ch-'a']) return true;
       return false;
   }
   void refnode(char ch, Node* newnode)
   {
       links[ch-'a']=newnode;
       
   }
   Node* nextNode(char ch)
   {
       return links[ch-'a'];
   }
   void increment_cnt_prefix()
   {
       cnt_prefix++;
   }
   void increment_end_with()
   {
       end_with++;
   }
    void decrement_end_with()
   {
       end_with--;
   }
   void decrement_cnt_prefix()
   {
       cnt_prefix--;
   }

};

class Trie{

    public:
     Node* root;
    Trie(){
        // Write your code here.
        root=new Node();
    }

    void insert(string &word){
        // Write your code here.
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containsletter(word[i]))
            {
              temp->refnode(word[i],new Node());
              temp=temp->nextNode(word[i]);
              temp->increment_cnt_prefix();
            }
            else
            {
                temp=temp->nextNode(word[i]);
                temp->increment_cnt_prefix();
            }
        }
        temp->increment_end_with();

    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containsletter(word[i])) return 0;
            temp=temp->nextNode(word[i]);
        }
        return temp->end_with;

    }

    int countWordsStartingWith(string &word){
        // Write your code here.
       Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
            if(!temp->containsletter(word[i])) return 0;
            temp=temp->nextNode(word[i]);
        }
        return temp->cnt_prefix;
    }

    void erase(string &word){
        // Write your code here.
        Node* temp=root;
        for(int i=0;i<word.size();i++)
        {
           temp=temp->nextNode(word[i]);
           temp->decrement_cnt_prefix();
        }
        temp->decrement_end_with();
    }
};
