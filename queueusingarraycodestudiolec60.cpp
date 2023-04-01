// all are O(1)
#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int size;
    int qfront;
    int rear;
public:
    Queue() {
       size=100000;
       arr=new int[size];
       qfront=0;
       rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(qfront==rear) return true;
        else return false;
    }

    void enqueue(int data) {
        if(rear==size) return;
        else arr[rear++]=data;
    }

    int dequeue() {
        if(qfront==rear) return -1;
        else 
        {
            int ans=arr[qfront];
            for (int i = 0; i < rear; i++) {
              arr[i] = arr[i + 1];
            }
            rear--;
            return ans;
        }
    }

    int front() {
        if(qfront==rear) return -1;
        else return arr[qfront];
    }
};