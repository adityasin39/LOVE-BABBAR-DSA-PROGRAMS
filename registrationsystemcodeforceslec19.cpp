#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int main() {
int n;
  cin>>n;
  unordered_map<string,int> freq;
  for(int i=0;i<n;i++)
    {
      string name;
      cin>>name;
      if(freq[name]==0) cout<<"OK"<<endl;
      else  cout<<name<<freq[name]<<endl;
      freq[name]++;
    }
  return 0;
}