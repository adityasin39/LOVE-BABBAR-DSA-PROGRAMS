// In this problem, first we insert all the words in the trie.
// here we have taken two pointers prev and curr so that we dont have to start and search for the 
// words from the beginning. If there is a link from prev then we mark curr at that link and then 
// do a dfs from curr till all the words are checked. If there is no link from prev then that means that there cant be any more suggestions so we break and return the answer.
// we take the use of a variable named as lastchar which is actually the current letter of the query and as we said if there is a link from prev for this lastchar then we add lastchar to prefix string which is then passed into the function addanswer where we do dfs and add letters in prefix until we complete a word and then we go on checking for all the words and as soon as the iteration for a particular letter ends we popback the letters for the next iteration.
//Here we need to pop back as the letter still remains added in the prefix.
// Phone Directory can be efficiently implemented using Trie Data Structure. We insert all the contacts into Trie. Generally search query on a Trie is to determine whether the string is present or not in the trie, but in this case we are asked to find all the strings with each prefix of ‘str’. This is equivalent to doing a DFS traversal on a graph. From a Trie node, visit adjacent Trie nodes and do this recursively until there are no more adjacent. This recursive function will take 2 arguments one as Trie Node which points to the current Trie Node being visited and other as the string which stores the string found so far with prefix as ‘str’. Each Trie Node stores a boolean variable ‘isLast’ which is true if the node represents end of a contact(word).

// // This function displays all words with given
// // prefix.  "node" represents last node when 
// // path from root follows characters of "prefix".
// displayContacts (TreiNode node, string prefix)
//     If (node.isLast is true)
//         display prefix

//         // finding adjacent nodes
//     for each character ‘i’ in lower case Alphabets 
//         if (node.child[i] != NULL)
//             displayContacts(node.child[i], prefix+i)
// User will enter the string character by character and we need to display suggestions with the prefix formed after every entered character. So one approach to find the prefix starting with the string formed is to check if the prefix exists in the Trie, if yes then call the displayContacts() function. In this approach after every entered character we check if the string exists in the Trie. Instead of checking again and again, we can maintain a pointer prevNode‘ that points to the TrieNode which corresponds to the last entered character by the user, now we need to check the child node for the ‘prevNode’ when user enters another character to check if it exists in the Trie. If the new prefix is not in the Trie, then all the string which are formed by entering characters after ‘prefix’ can’t be found in Trie too. So we break the loop that is being used to generate prefixes one by one and print “No Result Found” for all remaining characters. 


// C++ Program to Implement a Phone
struct Node
{
  Node* links[26];
  bool flag;
  Node()
  {
      for(int i=0;i<26;i++) links[i]=NULL;
      flag=false;

  }
};
class Trie
{
    Node* root;
  public:
   Trie()
   {
       root=new Node();
   }
   void insert(string word)
   {
      Node* temp=root;
      for(int i=0;i<word.size();i++)
      {
          if(!temp->links[word[i]-'a'])
          {
              Node* newnode=new Node();
              temp->links[word[i]-'a']=newnode;
          }
          temp=temp->links[word[i]-'a'];
      }
      temp->flag=true;
   }
void addanswers(Node* curr, vector<string>& temp, string prefix)
{
    if(curr->flag==true)
    {
        temp.push_back(prefix);
    }
    for(int i=0;i<26;i++)
    {
        if(curr->links[i])
        {
            prefix+=i+'a';
            addanswers(curr->links[i], temp, prefix);
            prefix.pop_back();
        }
    }
}
      
vector<vector<string>> getsuggestions(string str)
{
    Node* prev=root;
    vector<vector<string>> ans;
    string prefix="";
    for(int i=0;i<str.size();i++)
    {
        vector<string> particularqueryanswer;
       char lastchar=str[i];
       if(prev->links[lastchar-'a'])
       {
          prefix+=lastchar;
          Node* curr=prev->links[lastchar-'a'];
          addanswers(curr,particularqueryanswer,prefix);
          prev=curr;
       }
       else break;
       ans.push_back(particularqueryanswer);
    }

    return ans;
}

};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
      Trie trie;
      for(int i=0;i<contactList.size();i++)
      {
          trie.insert(contactList[i]);
      }
      return trie.getsuggestions(queryStr);

}