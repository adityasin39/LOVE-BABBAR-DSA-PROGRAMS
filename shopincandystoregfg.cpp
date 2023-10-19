    vector<int> candyStore(int candies[], int N, int K)
    {
       sort(candies,candies+N);
       int groups=N/(K+1);
       int mini=0;
       int maxi=0;
       int remaining=N%(K+1);
       if(remaining) groups+=1;
       int i=0;
       while(i<groups)
       {
           mini+=candies[i];
           i++;
       }
       i=N-1;
       int cnt=0;
        while(cnt<groups)
       {
           maxi+=candies[i];
           i--;
           cnt++;
       }
       return {mini,maxi};
    }
};