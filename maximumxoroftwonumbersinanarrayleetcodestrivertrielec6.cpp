//Approach 1 without trie
//Let us try to build the biggest XOR number binary digit by digit. So, the first question we are going to ask, is there two numbers, such that its XOR starts with 1...... (length is 32 bits). Howe we can find it? Let us use the idea of Problem 1: TwoSum: put all prefixes of lengh one to set and then try to find two numbers in this set such that their XOR starts with 1 (at first we have at most 2 elements in our set). Imagine that there are two numbers, which XOR starts with 1......, then the next question is there are two numbers with XOR starts with 11....., we again iterate through all numbers and find two of them with XOR starts with 11. It can happen that on the next step we did not find XOR starts with 111....., then we do not change our ans and on next step we are looking for XOR starts with 1101... and so on. So:

// We iterate, starting from the first digit in binary representation of number and go to the right.
// For each traversed digit we update our binary mask: in the beginning it is 10000...000, then it is 11000...000, 11100...000 and in the end 11111...111. We need this mask to quickly extract information about first several digits of our number.
// Create set of all possible starts of numbers, using num & mask: on the first iterations it will be first digit, on the next one first two digits and so on.
// Apply TwoSum problem: if we found two numbers with XOR starting with start, then we are happy: we update our ans and break for inner loop: so we continue to look at the next digit.
// Complexity: Time complexity is O(32n), because we traverse our numbers exactly 32 times. I do not like when this is called O(n) complexity, because we have quite big constant here. Space complexity is O(n).
// we are building maximum answer from left to right thus we send first bits of all numbers and then in the next iteration we send the first two bits and so on.
// a^b=c then b^c=a 
// we check if there exists a number which when xored with the max possible xor ie.start has other number which when xored with it gives start. 
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        int mask=0;
        for(int i=31;i>=0;i--)
        {
            mask=mask | (1<<i);
            unordered_set<int> st;
            for(int j=0;j<nums.size();j++)
            {
               st.insert(nums[j]&mask);
            }
            int start=ans | (1<<i);
            for(auto it:st)
            {
                if(st.count(start^it)>0)
                {
                    ans=start;
                    break;
                }
            }
        }
        return ans;
    }
};
//Approach 2 with trie
// struct Node
// {
//     Node* links[2];
//     Node()
//     {
//         links[0]=NULL;
//         links[1]=NULL;
//     }
//     bool containskey(int bit)
//     {
//         if(links[bit]) return true;
//         return false;
//     }
//     void makenexttrie(int bit, Node* newnode)
//     {
//         links[bit]=newnode;
//     }
//     Node* nexttrie(int bit)
//     {
//         return links[bit];
//     }
    
// };
// class Trie
// {
//   public:
//   Node* root;
//   Trie()
//   {
//       root=new Node();
//   }  
//   void insert(int num)
//   {
//      Node* temp=root;
//      for(int i=31;i>=0;i--) //insertion is always done from the left side.
//      {
//          int bit=(num>>i)&1; // getting the bit(bit is set or not) 
//          if(!temp->containskey(bit))
//          {
//            temp->makenexttrie(bit, new Node());
//          }
//          temp=temp->nexttrie(bit);
//      }   
//   }
//   int get_max(int num)
//   {
//     int max_xor=0;
//     Node* temp=root;
//     for(int i=31;i>=0;i--)
//     {
//         int bit=(num>>i)&1;
//         if(temp->containskey(1-bit)) //if the opposite bit exists
//         {
//             max_xor=max_xor| (1<<i); // making the corresponding answer bit=1
//             temp=temp->nexttrie(1-bit); 
//         }
//         else
//         {
//             temp=temp->nexttrie(bit);
//         }
//     }   
//     return max_xor;
//   }
// };
// class Solution {
// public:
//     int findMaximumXOR(vector<int>& nums) {
//         Trie trie;
//     for(int i=0;i<nums.size();i++)
//     {
//         trie.insert(nums[i]);
//     }
//     int maxi=0;
//     for(int i=0;i<nums.size();i++)
//     {
//         maxi=max(maxi,trie.get_max(nums[i]));
//     }
//     return maxi;
//     }
// };