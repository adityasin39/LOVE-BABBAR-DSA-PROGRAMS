// //Q.Length of string 
// #include<iostream>
// using namespace std;
// int main()
// {
//   char name[100];
//   cout<<"Enter your name"<<endl;
//   cin>>name;
//   int i;
//   for( i=0;name[i]!='\0';i++);
//   cout<<"The length of the char array is "<<i<<endl;
//     return 0;
// }
//Q.Reverse a string
#include<iostream>
using namespace std;
int main()
{
  char name[100];
  cout<<"Enter your name"<<endl;
  cin>>name;
  int l;
  for(l=0;name[l]!='\0';l++);
  int i=0;
  int j=l-1;
  while(i<j)
  {
    swap(name[i++],name[j--]);
  }
  cout<<name<<endl;
    return 0;
}