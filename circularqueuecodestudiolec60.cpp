// circular queue mein front and rear last index ke baad first index par aaenge
#include <bits/stdc++.h> 
class CircularQueue{
   
    public:
     int *arr;
    int size;
    int front;
    int rear;
    CircularQueue(int n){
        size=n;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        if(front==rear+1 || (front==0 && rear==size-1)) return false;
        if(front==-1)
        {
            front=0;
            rear=0;
            arr[rear]=value;
            return true;
        }
        if(rear==size-1) 
        {
            rear=0;
            arr[rear]=value;
            return true;
        }
        arr[++rear]=value;
        return true;

    }
 // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        if(front==-1) return -1;
        if(front==rear)
        {
            int ans=arr[front];
            front=-1;
            rear=-1;
            return ans;
        }
        if(front==size-1)
        {
            int ans=arr[front];
            front=0;
            return ans;
        }
        int ans=arr[front];
        front++;
        return ans;
    }
};