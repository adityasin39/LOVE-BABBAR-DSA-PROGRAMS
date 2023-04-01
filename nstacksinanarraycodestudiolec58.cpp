// can also be done by dividing the array in s/n parts but wont be space efficient
// if you dont understand then refer to love babbar
#include <bits/stdc++.h> 

class NStack
{
    int *arr;
    int n;
    int s;
    int *top;
    int *next;
    int freespot;
public:
    NStack(int N, int S)
    {
      n=N;
      s=S;
      arr=new int[s];
      top=new int[n];
      next=new int[s];
      freespot=0;
      for(int i=0;i<n;i++) top[i]=-1;
      for(int i=0;i<s-1;i++) next[i]=i+1;
      next[s-1]=-1;   
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        if(freespot==-1) return false;
        int idx=freespot;
        freespot=next[idx];
        arr[idx]=x;
        next[idx]=top[m-1];
        top[m-1]=idx;
        return true;

        
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        if(top[m-1]==-1) return -1;
        int idx=top[m-1];
        top[m-1]=next[idx];
        next[idx]=freespot;
        freespot=idx;
        return arr[idx];
        
    }
};