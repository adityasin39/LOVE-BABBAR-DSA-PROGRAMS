
//Love Babbars approach. 
// A very nice approach with less runtime. 
//in this approach , we take the xor of all the array elements.
//suppose the array is 1 3 4 3 2 , on taking xor we get 1^2^4, now if 
// i take the xor of 1st four numbers i.e. 1^2^3^4 and then xor this with 1^2^4 then i get 3 which is the duplicate number.
int findDuplicate(vector<int> &arr) 
{
    
    int ans=arr[0];
    for(int i=1;i<arr.size();i++)
    {
        ans=ans^arr[i];
    }
    for(int i=1;i<=arr.size()-1;i++)
    {
        ans=ans^i;
    }
    return ans;
	
}

// hare and tortoise. This question is different than the find the duplicate number as in that question the duplicate number could repeat more than twice but the solution of that question works here too.
int findDuplicate(vector<int> &arr) 
{
    int slow=arr[0];
    int fast=arr[0];
    do
    {
        slow=arr[slow];
        fast=arr[arr[fast]];
    }while(slow!=fast);
    fast= arr[0];
    while(slow!=fast)
    {
        slow=arr[slow];
        fast=arr[fast];
    }
    return slow;
// best approach 
int findDuplicate(vector<int> &arr) 
{
    vector<int> v(arr.size(),0);
    for(auto it: arr)
    {
        v[it]++;
        if(v[it]>1) return it;
    }
    return 0;
	
}

// tle maar diya. brute force.
int findDuplicate(vector<int> &arr) 
{
    int i,j;
    for(i=0;i<arr.size();i++)
    {
        for(j=0;j<arr.size();j++)
        {
            if(arr[j]==arr[i] && i!=j) return arr[i];
        }
    }
    return 0;
	
}
// tle
int findDuplicate(vector<int> &arr) 
{
    int i,j;
    for(i=0;i<arr.size();i++)
    {
        for(j=i+1;j<arr.size();j++)
        {
            if(arr[j]^arr[i]) continue;
            else
                return arr[i];
        }
        
    }
    return 0;
	
}
// tle
int findDuplicate(vector<int> &arr) 
{
    int i=0;
    int j=arr.size()-1;
    while(i<j)
    {
        if(arr[j]==arr[i]) return arr[i];
    }
    return 0;
	
}
// best approach.
int findDuplicate(vector<int> &arr) 
{
    vector<int> v(arr.size(),0);
    for(auto it: arr)
    {
        v[it]++;
        if(v[it]>1) return it;
    }
    return 0;
	
}

	
}
