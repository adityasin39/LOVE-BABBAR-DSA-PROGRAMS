// if you dont understand then refer to striver notes of this question
//Approach 1
// this is giving wrong answer for the last tc 
#include <bits/stdc++.h>
pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
   long long idealSum=(n*(n+1))/2;
   long long actualSum=0;
   for(int i=0;i<n;i++)
   {
      actualSum+=arr[i];
   }
   long long idealSquareSum=(n*(n+1)*(2*n+1))/6;
   long long actualSquareSum=0;
   for(int i=0;i<n;i++)
   {
        actualSquareSum+=(long long)arr[i]*(long long)arr[i];
   }
   long long diffSum=actualSum-idealSum;
   long long diffSquareSum=actualSquareSum-idealSquareSum;
   pair<int,int> ans;
   ans.second=(int)(((long long)(diffSum+(diffSquareSum/diffSum))/2));
   ans.first=(int)(ans.second-diffSum);
   return ans;
}
//Approach 2
// #include <bits/stdc++.h>
// pair<int,int> missingAndRepeating(vector<int> &arr, int n)
// {
//    int val=0;
//    for(int i=0;i<n;i++) val^=arr[i];
//    for(int i=1;i<=n;i++) val^=i;
//    int bit=-1;
//    int bitNo=-1;
//    for(int i=0;i<32;i++)
//    {
//       bit=(1<<i)&val;
//       if(bit!=0)
//       {
//          bitNo=i;
//          break;
//       }
//    }
//    int oneClub=0;
//    int zeroClub=0;
//    for(int i=0;i<n;i++)
//    {
//       int temp=(1<<bitNo)&arr[i];
//       if(temp!=0)
//       {
//          oneClub^=arr[i];
//       }
//       else zeroClub^=arr[i];
//    }
//    for(int i=1;i<=n;i++)
//    {
//       int temp=(1<<bitNo)&i;
//       if(temp!=0)
//       {
//          oneClub^=i;
//       }
//       else zeroClub^=i;
//    }
//    pair<int,int> ans;
//    for(int i=0;i<n;i++)
//    {
//       if(arr[i]==oneClub)
//       {
//          ans.second=oneClub;
//          ans.first=zeroClub;
//          return ans;
//       }
//    }
//          ans.second=zeroClub;
//          ans.first=oneClub;
//    return ans;
// }
