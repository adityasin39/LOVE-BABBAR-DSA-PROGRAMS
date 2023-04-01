#include <bits/stdc++.h> 
class TwoStack {
// the logic is to insert elements of stack 1 from start and insert elements of stack 2 
// from end
public:
  int s;
  int top1;
  int top2;
  int *arr;
    // Initialize TwoStack.
    TwoStack(int s) {
        // Write your code here.
        this->s=s;
        top1=-1;
        top2=s;
        arr=new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        // Write your code here.
        if(top1==top2-1 || top1>=s-1)
        {
            return;
        } 
        else {
          top1++;
          arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        // Write your code here.
        if(top2==top1+1 || top2<=0)
        {
            return;
        }
        else
        {
            top2--;
            arr[top2]=num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        // Write your code here.
        if(top1==-1) return -1;
        else
        {
            int temp=arr[top1];
            top1--;
            return temp;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        // Write your code here.
         if(top2==s) return -1;
        else
        {
            int temp=arr[top2];
            top2++;
            return temp;
        }
    }
};
