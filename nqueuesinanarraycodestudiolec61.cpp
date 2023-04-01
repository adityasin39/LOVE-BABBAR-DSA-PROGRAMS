// can also be done by dividing the array in s/n parts but wont be space efficient
// if you dont understand then refer to love babbar
#include <bits/stdc++.h> 
class NQueue{
public:
    int *arr;
    int n;
    int s;
    int freespot;
    int *front;
    int *rear;
    int *next;
    NQueue(int n, int s){
        this->n=n;
        this->s=s;
        arr=new int[s];
        next=new int[s];
        front=new int[n];
        rear=new int[n];
        for(int i=0;i<n;i++) 
        {
            front[i]=-1;
            rear[i]=-1;
        }
        for(int i=0;i<s-1;i++) next[i]=i+1;
        next[s-1]=-1;
        freespot=0;
            }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        if(freespot==-1) return false;
        int idx=freespot;
            freespot=next[idx];
        if(front[m-1]==-1)
        {
            front[m-1]=idx;

        }
        else 
        {
            next[rear[m-1]]=idx;
        }
        rear[m-1]=idx;
        next[idx]=-1;
        arr[idx]=x;
        return true;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        if(front[m-1]==-1) return -1;
        int idx=front[m-1];
        front[m-1]=next[idx];
        next[idx]=freespot;
        freespot=idx;
        return arr[idx];
    }
};