// using a single queue
// if you dont understand then refer to https://www.youtube.com/watch?v=jDZQKzEtbYQ
class MyStack {
public:
queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int n=q.size();
        for(int i=0;i<n-1;i++)
        {
            int val=q.front();
            q.pop();
            q.push(val);
        }
    }
    
    int pop() {
         if(q.empty()) return -1;
        int ans=q.front();
        q.pop();
        return ans;
        
    }
    
    int top() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
         if(q.empty()) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
 // using two queues
//  class MyStack {
// public:
//     queue<int> q1;
//     queue<int> q2;
//     MyStack() {
//     }
    
//     void push(int x) {
//         q1.push(x);
//         while(!q2.empty())
//         {
//             q1.push(q2.front());
//             q2.pop();
//         }
//         swap(q1,q2);
//     }
    
//     int pop() {
//         if(q2.empty()) return -1;
//         int ans=q2.front();
//         q2.pop();
//         return ans;
        
//     }
    
//     int top() {
//         if(q2.empty()) return -1;
//         return q2.front();
//     }
    
//     bool empty() {
//         if(q2.empty()) return true;
//         else return false;
//     }
// };

// /**
//  * Your MyStack object will be instantiated and called as such:
//  * MyStack* obj = new MyStack();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->top();
//  * bool param_4 = obj->empty();
//  */