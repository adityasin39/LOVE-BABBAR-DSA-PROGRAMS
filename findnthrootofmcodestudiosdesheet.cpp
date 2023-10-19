int NthRoot(int n, int m) {
  // Write your code here.
  if(m==1) return 1;
  int start=0;
  int end=m/n;
  while(start<=end)
  {
    int mid=start+(end-start)/2;
    int temp=mid;
    for(int i=0;i<n-1;i++) mid*=mid;
    if(mid==m) return temp;
    else if(mid>m) end=temp-1;
    else start=temp+1;
  }
  return -1;
}