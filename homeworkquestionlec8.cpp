//AP
#include<iostream>
using namespace std;
int nthterm(int n)
{
  int ans;
  ans=3*n+7;
  return ans;
}
int main()
{
  int n;
  cin>>n;
  int ans=nthterm(n);
  cout<<ans<<endl;
}
//TOTAL NO OF SET BITS OF A AND B COMBINED.
#include<iostream>
using  namespace std;
int totalnoofsetbits(int a,int b)
{
  int counta=0;
  int countb=0;
  while(a!=0||b!=0)
    {
      int bita=a&1;
      if(bita==1)counta++;
      a=a>>1;
      int bitb= b&1;
      if(bitb==1)countb++;
      b=b>>1;
    }
  return (counta+countb);
}
int main()
{
int a,b;
  cin>>a>>b;
  int ans=totalnoofsetbits( a, b);
cout<<ans<<endl;


  
  return 0;
}
//NTH TERM OF FIBONACCI SEQUENCE
#include<iostream>
using namespace std;
int fibo(int n)
{
  int a=0;
  int b=1;
  int ans,c;
  if(n==1 || n==2)
  {
    return n-1;
  }
  while(n-2)
    {
    c=a+b;
      a=b;
      b=c;
      n--;
    }
  ans=c;
  return ans;
}
int main()
{
int n;
  cin>>n;
  int ans=fibo(n);
cout<<ans<<endl;
return 0;
}