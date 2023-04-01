// Approach 1 using the queue concept by having start and end pointers
// if you dont understand then refer to love babbar video
//  int start=0;
//       int balance=p[start].petrol-p[start].distance;
//       while(start<n && balance<0) // finding the first valid start position
//       {
//           start++;
//          balance=p[start].petrol-p[start].distance;
//       }
//       if(start==n) return -1;
//       int end=(start+1)%n; // for cirular turn
//       int prevstart=start;
//       while(start!=end)
//       {
//           balance+=p[end].petrol-p[end].distance;
//           if(balance>=0) end=(end+1)%n;
//           else
//           {
//               start=(end+1)%n; 
//               if(start>prevstart) // agar this is false then it means ki ham waapas piche aagaye
//               {
                  
//                   balance=0;
//                 balance=p[start].petrol-p[start].distance;
//                  while(start<n && balance<0)
//               {
//           start++;
//          balance=p[start].petrol-p[start].distance;
//                   }
//       if(start==n) return -1;
//               prevstart=start;
//                   end=(start+1)%n;
//               }
//               else return -1;
//           }
//       }
//       return start;
// Approach 2 using deficit concept
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
      int start=0;
      int balance=0;
      int deficit=0;
      for(int i=0;i<n;i++)
      {
          balance+=p[i].petrol-p[i].distance;
          if(balance<0)
          {
              start=i+1;
              deficit+=balance;
              balance=0;
          }
      }
      return balance+deficit>=0 ? start : -1;
    }
};