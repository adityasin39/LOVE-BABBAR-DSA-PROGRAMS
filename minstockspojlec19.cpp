#include<bits/stdc++.h>
using namespace std;
int main() {
 int n;
  cin>>n;
  map<string,int> m;
  set<pair<int,string>> s; // set isliye use kiya hai kyonki minimum price nikalne ke liye agar for loop use kiya toh tle maarega.
  string stock;
  int price;
  int type;
  for(int i=1;i<=n;i++)
    {
      cin>>type;
      if(type==1 )
      {
        cin>>stock;
        cin>>price;
        m[stock]=price;
        s.insert(make_pair(price,stock));
      }
        else if (type==2)
        {
          cin>>stock;
          cin>>price;
          s.erase(s.find(make_pair(m[stock],stock))); // agar stock ka price change hua toh iska matlab purana stock hat jaaega market se.
          m[stock]=price;
        s.insert(make_pair(price,stock));
        }

  else
      {
        cin>>stock;
        
        cout<<s.begin()->second<<" "<<i<<endl;
        s.erase(s.begin());// jo stock kharid liya wo waapas available nahi hoga

      }
  }
  return 0;
}