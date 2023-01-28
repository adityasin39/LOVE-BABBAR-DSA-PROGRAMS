 class Solution {
public:   
  double myPow(double x, int n) {
      
long m;
if(n>0)m=(long)n;
else
{
    m=-1*(long)n;//int ka min value is 1 greater than the max value thus positive banane par range cross ho jaaegi hence long use kiya hai.
}
double ans=1.0;
while(m)
{
    if(m%2)
    {
        ans=ans*x;
        m=m-1;
    }
    else
    {
        x=x*x;
        m=m/2;
    }
}
if(n>0)return ans;
else
return 1/ans;


 
        
        
  }      
     };











// //brute force wala solution with TLE.
// class Solution {
// public:
//     double myPow(double x, int n) {
//         if(x==1.0)return 1;
//         double ans=1.0;
//         long m;
//         if(n>0)
//         {
//         m=(long)n;
//         }
//         else
//         {
//             m=-1*(long)n;
//         }
        
//         for(long i=1;i<=m;i++)ans=ans*x;
//         if(n>0)
//         return ans;
//         else
//         return 1/ans;
    
//         }
        
        
       
    
// };


