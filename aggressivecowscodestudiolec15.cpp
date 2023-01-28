// agar nahi samajh aaye toh refer to love babbars video(i.e original video)
bool isPossible(vector<int> &stalls, int k,int mid)
{
    int cowCount=1;
    int lastpos=stalls[0];
    for(int i=1;i<stalls.size();i++)
    {
        if(stalls[i]-lastpos>=mid)
        {
            cowCount++;
            if(cowCount==k) return true;
            lastpos=stalls[i];
        }   
    }
    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(),stalls.end());
    int start=0;
    int end=stalls[stalls.size()-1]-stalls[0];
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(isPossible(stalls,k,mid))
        {
            ans=mid;
            start=mid+1;
        }
        else end=mid-1;
    }
    return ans;
}