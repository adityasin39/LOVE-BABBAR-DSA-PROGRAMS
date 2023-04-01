#include<iostream>
#include<deque>
using namespace std;
void display(deque<int> dq)
{
    for(int i=0;i<dq.size();i++)
    {
        cout<<dq[i]<<" ";
    }
}
int main(){
    deque<int> dq={1,3,4};
    cout<<dq.empty()<<endl;
    display(dq);
    dq.push_back(4);
    display(dq);
    dq.push_front(5);
    display(dq);
    dq.pop_back();
    display(dq);
    dq.pop_front();
    display(dq);
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    dq.clear();
    cout<<dq.empty()<<endl;
    
    
    
    return 0;
}