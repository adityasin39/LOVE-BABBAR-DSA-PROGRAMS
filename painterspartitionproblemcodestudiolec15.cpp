// yaha dono painter ne same time pe chalu kiya kaam karna toh dono mein se joh maximum time hoga woh ham baaki cases se compare karenge and the minumium of all the cases will be our answer just like allocate books problem.
bool isPossible(vector<int> &boards, int n, int k,int mid)
{
    int painterCount=1;
    int timeSum=0;
    for(int i=0;i<n;i++)
    {
        if(timeSum+boards[i]<=mid)
        {
            timeSum+=boards[i];
        }
        else
        {
            painterCount++;
            if(painterCount>k || boards[i]>mid) return false;
            timeSum=0;
            timeSum=boards[i];
        }

        }
    return true;
    
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int n=boards.size();
    int start=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=boards[i];
    }
    int end=sum;
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(boards,n,k,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
            start=mid+1;
    }
    return ans;
}