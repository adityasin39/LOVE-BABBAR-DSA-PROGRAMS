#include <bits/stdc++.h>
void sortedinsert(stack<int> &stack, int val)
{
    if(stack.empty())
    {
        stack.push(val);
        return;
    }
    int temp=stack.top();
    if(val<temp)
    {
        stack.pop();
    }
    else
    {
        stack.push(val);
        return;
    }
    sortedinsert(stack,val);
    stack.push(temp);
} 
void sortStack(stack<int> &stack)
{
     	if(stack.empty())
         {
             return;
         }
         int val=stack.top();
         stack.pop();
         sortStack(stack);
         sortedinsert(stack,val);
}