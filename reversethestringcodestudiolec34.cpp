#include <bits/stdc++.h> 
void rev(string& s,int left,int right) // pass by reference kiya hai nahi toh sirf copy reverse ho jaati
{
    if(left>right) return;
    swap(s[left],s[right]);
    left++;
    right--;
    return rev(s,left,right);
}
string reverseString(string str)
{
     int left=0;
    int right=str.size()-1;
	rev(str, left,right);
	return str;
}