#include <bits/stdc++.h> 
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    stack<int> newstack;
    while(!myStack.empty())
    {
        int temp=myStack.top();
        myStack.pop();
        newstack.push(temp);
    }
    myStack.push(x);
    while(!newstack.empty())
    {
        int temp=newstack.top();
        newstack.pop();
        myStack.push(temp);
    }
    return myStack;
}
