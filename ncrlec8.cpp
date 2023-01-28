#include<iostream>
using namespace std;
void ncr(int n,int r)
{
 if(r==0)
{cout<<n;}
  else
{
  

    int num=1;
    int dem=1;
    int m=r;
    for(int i=0;i<m;i++)
    {
        num=num*n;
        n--;
        dem=dem*r;
        r--;
    }
    cout<<num/dem<<endl;
  } 
}

int main()
{
    int n,r;
    cout<<"Enter the value of n and r"<<endl;
    cin>>n>>r;
  ncr(n,r);
    return 0;
}