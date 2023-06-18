// before solving this problem, we must understand another problem which deals with the crux concept of this problem.
//given an array of numbers and a number x. find the max value of arr[i]^x
// in this case the trie will have two links one for 0 and the other for 1 and we will insert all the array elements
// in the trie bitwise starting from the 31st bit as done in the insertion function below.
// if we do xor of opposite bits i.e. 0 and 1 then we get 1. In order to maximize the xor, we want bits which are opposite to x's bits.
// So we start from the 31st bit and check if there is an opposite bit by checking if there is a link to another trie from that bit. If it exists then we turn on the 31st or the corresponding bit of our answer and then we go to the next trie of that opposite bit.
// If the opposite bit doesnt exist then we dont do anything to the answer and move to the next trie of that bit which didnt have its opposite bit.
// In this problem, we have inserted arr1 elements in the trie and then we have sent the arr2 elements one by one as x and then we have found m max_xor from which the maximum one is our answer.
// TC=O(n*32+m*32) so this is very less as compared to the brute force TC=O(n*m)
// SC cant be predicted in case of a trie. It will be like 1X2X4X8... and in the worst case SC=O(n*32)
// if you still dont understand then refer to strivers article of this question.
struct Node
{
    Node* links[2];
    Node()
    {
        links[0]=NULL;
        links[1]=NULL;
    }
    bool containskey(int bit)
    {
        if(links[bit]) return true;
        return false;
    }
    void makenexttrie(int bit, Node* newnode)
    {
        links[bit]=newnode;
    }
    Node* nexttrie(int bit)
    {
        return links[bit];
    }
    
};
class Trie
{
  public:
  Node* root;
  Trie()
  {
      root=new Node();
  }  
  void insert(int num)
  {
     Node* temp=root;
     for(int i=31;i>=0;i--) //insertion is always done from the left side.
     {
         int bit=(num>>i)&1; // getting the bit(bit is set or not) 
         if(!temp->containskey(bit))
         {
           temp->makenexttrie(bit, new Node());
         }
         temp=temp->nexttrie(bit);
     }   
  }
  int get_max(int num)
  {
    int max_xor=0;
    Node* temp=root;
    for(int i=31;i>=0;i--)
    {
        int bit=(num>>i)&1;
        if(temp->containskey(1-bit)) //if the opposite bit exists
        {
            max_xor=max_xor| (1<<i); // making the corresponding answer bit=1
            temp=temp->nexttrie(1-bit); 
        }
        else
        {
            temp=temp->nexttrie(bit);
        }
    }   
    return max_xor;
  }
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie trie;
    for(int i=0;i<n;i++)
    {
        trie.insert(arr1[i]);
    }
    int maxi=0;
    for(int i=0;i<m;i++)
    {
        maxi=max(maxi,trie.get_max(arr2[i]));
    }
    return maxi;
}