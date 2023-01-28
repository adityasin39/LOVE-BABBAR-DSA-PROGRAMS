#include <bits/stdc++.h>>
using namespace std;
int main() {
  // second order statistics means 2nd smallest unique element
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++) cin>>arr[i];
  set<int> s;
  for(int i=0;i<n;i++) s.insert(arr[i]);
  if(s.size()==1) cout<<"NO";
  else{
    auto it=s.begin();
    it++;
    cout<<*it;
  }
  
}