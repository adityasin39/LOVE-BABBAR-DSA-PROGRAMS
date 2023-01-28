#include <bits/stdc++.h> 
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    // 2 pointer approach used in many array questions.
    // brute force mein tle maar dega.
    // the main trick here is to use the logic that the arrays are sorted.
    //Two pointers is really an easy and effective technique that is typically used for searching pairs in a sorted array.
    vector<int> res;
    int i=0,j=0;
    while(i<n && j<m)
    {
        if(arr1[i]<arr2[j]) i++;
        else if(arr1[i]==arr2[j])
        {
            res.push_back(arr2[j]);
            i++;
            j++;
        }
        else j++;
    }
     return res;
}