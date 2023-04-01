// one more brute force approach which takes O(n) space is taking two stacks and storing the value and the current minimum element in the stacks respectively.
// Approach 1 
// if you dont understand any of the two approaches then refer to https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/
// #include<bits/stdc++.h>
// class SpecialStack {
//     // Define the data members.

//     /*----------------- Public Functions of SpecialStack -----------------*/
//     public:
//     stack<int> st;
//     int minEle;
//     void push(int data) {
//         if(st.empty())
//         {
//             minEle=data;
//             st.push(data);
//         }
//         else if(data>=minEle) st.push(data);
//         else
//         {
//             int y=2*data-minEle;
//             minEle=data;
//             st.push(y);
//         }
//     }

//     int pop() {
//         if(st.empty()) return -1;
//         int val=st.top();
//         if(val>=minEle)
//         {
//             st.pop();
//             return val;
//         }
//         else
//         {
//             int ans=minEle;
//             minEle=2*minEle-val;
//             st.pop();
//             return ans;
//         }
//     }

//     int top() {
//         if(st.empty()) return -1;
//         int y=st.top();
//         if(y<minEle)
//         {
//             return minEle;
//         }
//         else return st.top();
//     }

//     bool isEmpty() {
//         if(st.empty()) return true;
//          return false;
//     }

//     int getMin() {
//         if(st.empty()) return -1;
//         return minEle;
//     }  
// };
//Approach 2 using a pair of the current value and the current minimum element in the stack with O(1) TC and O(1) SC
class MinStack {
public:
  stack<pair<int,int>> st;
        int minEle;
    MinStack() {
      
    }
    
    void push(int val) {
        if(st.empty())
        {
           minEle=val;
           st.push({val,minEle});
        }
        else
        {
            minEle = std::min(minEle, val);
        st.push({val, minEle});
        }
    }
    
    void pop() {
        if(st.empty()) return;
         st.pop();
         if(!st.empty())
         minEle=st.top().second;
         return;
    }
    
    int top() {
        if(st.empty()) return -1;
        return st.top().first;
    }
    
    int getMin() {
        if(st.empty()) return -1;
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */