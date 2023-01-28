// Approach 1
// #include <bits/stdc++.h> 
// vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
//    vector<int> ans;
//     int num1=0;
//     for(int i=0;i<n;i++)
//     {
//         num1+=a[i]*pow(10,n-i-1);
//     }
//     int num2=0;
//       for(int i=0;i<m;i++)
//     {
//         num2+=b[i]*pow(10,m-i-1);
//       }
//     int sum=num1+num2;
//     int rem;
//     while(sum)
//     {
//         rem=sum%10;
//         ans.push_back(rem);
//         sum/=10;
//     }
//     reverse(ans.begin(),ans.end());
//     return ans;
// }
// Approach 2
#include <bits/stdc++.h> 
vector<int> findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	vector<int> ans;
    int i=n-1;
    int j=m-1;
    int carry=0;
    while(i>=0 && j>=0)
    {
        int sum=carry+a[i--]+b[j--];
        ans.push_back(sum%10);
        carry=sum/10;
                if(i<0 && j<0 && carry==1) ans.push_back(1);// this line is written for cases where 1 is carried at the end like 999 + 999 =1998

    }
    while(i>=0)
    {
        int sum=carry+a[i--];
         ans.push_back(sum%10);
        carry=sum/10;
        if(i<0 && carry==1) ans.push_back(1); // for the last one that is carried.
    }
     while(j>=0)
    {
        int sum=carry+b[j--];
         ans.push_back(sum%10);
        carry=sum/10;
                 if(j<0 && carry==1) ans.push_back(1);

     }
    reverse(ans.begin(),ans.end());
    return ans;
    
}