// best approach with TC=O(n) and SC=O(1)
vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
                vector<long long> ans;
                int firstnegativeindex=0;
                for(int i=K;i<=N;i++)
                {
                    while(firstnegativeindex<i && ( firstnegativeindex<i-K || A[firstnegativeindex]>=0))// skipping all non negative elements and those which are out of the window
                    firstnegativeindex++;
                    if( firstnegativeindex<i && A[firstnegativeindex]<0)
                    {
                        ans.push_back(A[firstnegativeindex]);
                    }
                    else ans.push_back(0);
                    
                }
                return ans;
 }
 // deque approach, can be done through queue too but dq is faster than q for large input
 // if you dont understand then refer to love babbar or chatgpt
//   vector<long long> ans;
//   deque<int> dq;
//   for(int i=0;i<K;i++)
//   {
//       if(A[i]<0)
//       {
//           dq.push_back(i);
//       }
//   }
//   for(int i=K;i<=N;i++)
//   {
//       if(!dq.empty()) ans.push_back(A[dq.front()]);
//       else ans.push_back(0);
//       if(i==N) break;
//       if(!dq.empty() && dq.front()<i-K+1) dq.pop_front();
//       if(A[i]<0) dq.push_back(i);
//   }
//   return ans;
   // brute force which gives tle
//   vector<long long> ans;
//               long long left=0;
//               long long right=left+K-1;
//               long long j=0;
//               while(right<=N-1)
//               {
                   
//               long long i=left;
//               while(i!=right+1)
//               {
//                   if(A[i]<0) 
//                   {
//                       ans.push_back(A[i]);
//                       break;
//                   }
//                   i++;
//               }
//               if(i==right+1) ans.push_back(0);
//               left+=1;
//               right+=1;
//               }
//               return ans;