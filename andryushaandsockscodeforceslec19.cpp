#include<bits/stdc++.h>
using namespace std;
int main() {
int n;
  cin>>n;
  set<int> table;
  set<int> maximum;
  for(int i=0;i<2*n;i++)
    {
        int sock;
        cin>>sock;
      if(table.find(sock)==table.end())
      {
        table.insert(sock);
        maximum.insert(table.size());
      }
      else 
      {
        table.erase(sock);
      }
    }
  auto it=maximum.end();
  cout<<*it;
  
}
// 2nd method which is a lot better than the first one.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==1) cout<<1;
    else{
        int arr[n+1]={0};
        int maximum=0;
        int tablecount=0;
        for(int i=0;i< 2*n;i++)
        {
            int sock;
            cin>>sock;
            if(arr[sock]==0)
            {
                arr[sock]++;
                tablecount++;
            
                maximum=max(maximum,tablecount);
            }
            else tablecount--;
        }
        cout<<maximum;
    }
    return 0;
}