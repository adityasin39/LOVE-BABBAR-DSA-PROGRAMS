int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int,int> mp;
    int maxF=0;
    int ans=-1;
    for(int i=0;i<n;i++)
    {
        mp[arr[i]]++;
        maxF=max(maxF,mp[arr[i]]);
    }
    
    for(int i=0;i<n;i++)
    {
        if(mp[arr[i]]==maxF)
        {
            ans=arr[i];
            return ans;
        }
    }
}