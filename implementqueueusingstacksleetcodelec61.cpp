//using two stacks and amortized one
// push is O(1) while peek and pop are amortized O(1) which means that most of the time they are O(1) and rest of the time O(n)
// if you dont understand then refer to https://www.youtube.com/watch?v=3Et9MrMc02A
class MyQueue {
public:
stack<int> input;
stack<int> output;
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()) 
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            if(output.empty()) return -1;
            else
            {
                int ans=output.top();
                output.pop();
                return ans;
            }
        }
        int ans=output.top();
        output.pop();
        return ans;
    }
    
    int peek() {
        if(output.empty()) 
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            if(output.empty()) return -1;
            else
            {
                return output.top();
            }
        }
        return output.top();
    }
    
    bool empty() {
        if(output.empty()) 
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
            if(output.empty()) return true;
            else
            {
                return false;
            }
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
 // using two stacks not amortized
//  class MyQueue {
// public:
// stack<int> st1;
// stack<int> st2;
//     MyQueue() {
        
//     }
    
//     void push(int x) {
//         while(!st1.empty())
//         {
//             st2.push(st1.top());
//             st1.pop();
//         }
//         st1.push(x);
//         while(!st2.empty())
//         {
//             st1.push(st2.top());
//             st2.pop();
//         }
//     }
    
//     int pop() {
//         if(st1.empty()) return -1;
//         int ans=st1.top();
//         st1.pop();
//         return ans;
//     }
    
//     int peek() {
//          if(st1.empty()) return -1;
//          return st1.top();
//     }
    
//     bool empty() {
//          if(st1.empty()) return true;
//          return false;
//     }
// };

// /**
//  * Your MyQueue object will be instantiated and called as such:
//  * MyQueue* obj = new MyQueue();
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * int param_3 = obj->peek();
//  * bool param_4 = obj->empty();
//  */