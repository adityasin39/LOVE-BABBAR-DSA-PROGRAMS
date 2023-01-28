// without using map.
#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  int count=n;
  vector<int> boxx;
  for(int i=0;i<n;i++)
    {
      int box;
      cin>>box;
      boxx.emplace_back(box);
    }
  sort(boxx.begin(),boxx.end());
  int i=0;
  int j=1;
  while(j!=n)
    {
      if(boxx[i]!=boxx[j])
      {
        count--;
        j++;  
      }
      else
      {
        while(j<n && boxx[j]==boxx[j+1]) j++;
        j++;
        if(boxx[i]!=boxx[j] && j<n)
        {
          count--;
          j++;
        }
      }
      i++;
    }
    
  cout<<count;
  return 0;
}
// 2nd approach by using map and heavyweight thinking.
// on thinking a lot, we get to know that the box size with the highest frequency will contain all the smaller boxes and the resulting boxes can be easily contained into larger boxes.
// So, the answer is the highest frequency thus we use map here.
//you can always show that the answer is equal to the amount of boxes of the size appearing the most in array. Result can be easily obtained by constructive algorithm: take these most appearing boxes, put smaller boxes in decreasing order of their size into free ones (there always be space) and put resulting boxes into the larger ones in increasing order.

// Overall complexity: O(nlogn)
// if you still dont understand then refer to this video https://www.youtube.com/watch?v=9BGkcWSQhIQ
#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin>>n;
  map<int,int> m;
  vector<int> box;
  for(int i=0;i<n;i++)
    {
      int boxlength;
      cin>>boxlength;
      box.emplace_back(boxlength);
    }
  for(auto it: box) m[it]++;
  auto itr=m.begin();
  int max=(itr->second);
  for(auto it=m.begin();it!=m.end();it++)
    {
      if(max<it->second)
      {
        max=it->second;
      }
    }
  cout<<max;
  return 0;
}