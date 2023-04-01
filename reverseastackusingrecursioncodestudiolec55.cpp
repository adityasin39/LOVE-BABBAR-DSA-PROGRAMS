#include<bits/stdc++.h>
void insertatbottom(stack<int> &stack, int num)
{
    if(stack.empty())
    {
        stack.push(num);
        return;
    }
    int temp=stack.top();
    stack.pop();
    insertatbottom(stack, num);
    stack.push(temp);
}
void reverseStack(stack<int> &stack) {
    if(stack.empty())
    {
        return;
    }
    int val=stack.top();
    stack.pop();
    reverseStack(stack);// baaki stack ko recursion reverse kar dega 
    insertatbottom(stack,val);// so the question goes down to insertionatbottom
}