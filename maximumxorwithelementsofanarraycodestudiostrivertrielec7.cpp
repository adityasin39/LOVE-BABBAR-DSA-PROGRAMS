// in this approach we want only those elements in the trie which are <=Ai so as these are online queries we make them offline queries by sorting them according to Ai and we have to sort the arr too , in this way we will be able to insert elements step by step and we will have only required elements in the trie.
// but we want our answer in the correct order so we push the index too in the vector queries.
//TC=O(qlogq+nlogn) SC=O(n)
#include<bits/stdc++.h>
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
	Node* root;
	public:
    Trie()
	{
		root= new Node();
	}
    void insert(int num)
  {
     Node* temp=root;
     for(int i=31;i>=0;i--) //insertion is always done from the left side.
     {
         int bit=(num>>i)&1; // getting the bit(bit is set or not)
         if (!temp->containskey(bit)) {
           temp->makenexttrie(bit, new Node());
         }
         temp = temp->nexttrie(bit);
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

bool compareRows(const std::vector<int>& row1, const std::vector<int>& row2) {
    // Compare based on the values in the first column of each row
    return row1[1] < row2[1];
}

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){
	//	Write your coode here.
	for(int i=0;i<queries.size();i++)
	{
		queries[i].push_back(i);
	}
	sort(queries.begin(),queries.end(),compareRows);
	Trie trie;
	sort(arr.begin(),arr.end());
	vector<int> res(queries.size());
	int j=0;
	int prevj;
	for(int i=0;i<queries.size();i++)
	{
		prevj=j;
		int ans=-1;
        while(j<arr.size())
		{
           if(arr[j]<=queries[i][1])
		   {
			   
			   trie.insert(arr[j]);
			
		   }
		   else break;
		   j++;
		}
		if(j>0)
		ans=max(ans,trie.get_max(queries[i][0]));
		res[queries[i][2]]=ans;
	}

	return res;
}