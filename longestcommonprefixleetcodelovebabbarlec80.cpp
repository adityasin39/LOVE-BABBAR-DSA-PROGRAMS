// Approach 1
// In this approach, we want to know the lexographically max and min strings because if we know them and we compare only these two strings then all the middle ones will have the common part as all the middle ones will be in lexographically in the middle of these two strings.
//TC=O(n) and The space used by the two string variables s1 and s2 is proportional to the length of the longest string in the array. Therefore, the space complexity is O(1) as it does not depend on the size of the input array.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string first=strs[0];
        string last=strs[0];
      for(int i=1;i<strs.size();i++)
      {
          first=min(first,strs[i]);
          last=max(last,strs[i]);
      }
      string prefix="";
      int idx=0;
      while(idx<first.length()) // as first is shorter.
      {
          if(first[idx]!=last[idx])
          {
              break;
          }
          else prefix+=first[idx];
          idx++;
      }
      return prefix;
    }
};
//Approach 2 
// TC=O(m*n) SC=O(m*n)
// here we just check the number of links. If it is greater than 1 that means we cant have more common characters so we break out of the loop.
// struct Node
// {
//   Node* links[26];
//   bool flag;
//   Node()
//   {
//       for(int i=0;i<26;i++) links[i]=NULL;
//       flag=false;

//   }
// };
// class Trie
// {
//     Node* root;
//   public:
//    Trie()
//    {
//        root=new Node();
//    }
//    void insert(string word)
//    {
//       Node* temp=root;
//       for(int i=0;i<word.size();i++)
//       {
//           if(!temp->links[word[i]-'a'])
//           {
//               Node* newnode=new Node();
//               temp->links[word[i]-'a']=newnode;
//           }
//           temp=temp->links[word[i]-'a'];
//       }
//       temp->flag=true;
//    }
//    string lcp()
//    {
//        Node* temp=root;
//        string prefix="";
//        while(temp->flag!=true){
//        int cnt=0;
//        int index=-1;
//        for(int i=0;i<26;i++)
//        {
           
//           if(temp->links[i])
//           {
//               index=i;
//               cnt++;
//           }
//           if(cnt>1) return prefix;
//        }
//        prefix+=index+'a';
//        temp=temp->links[index];
//        }
//        return prefix;
//    }
// };
// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         // Trie trie;
//         // for(int i=0;i<strs.size();i++)
//         // {
//         //     trie.insert(strs[i]);
//         // }
//         // string ans=trie.lcp();
//         // return ans;
//     }
// };