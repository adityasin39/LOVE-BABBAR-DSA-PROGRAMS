// better optimized approach with great space complexity
class StockSpanner {
public:
    stack<pair<int,int>> st;
    StockSpanner() {
    }
    
    int next(int price) {
       int span=1;
       while(!st.empty() && st.top().first<=price)
       {
           span+=st.top().second;
           st.pop();
       }
       st.push({price,span});
       return span;
    }
};
// normal approach
// class StockSpanner {
// public:
//         int i=0;
//         vector<int> arr;
//         stack<int> st;
//     StockSpanner() {
//     }
    
//     int next(int price) {
//         i++;
//         int ans=0;
//         arr.push_back(price);
//         while(!st.empty() && arr[st.top()]<=arr[i-1]) st.pop();
//         if(st.empty()) ans=i;
//         else ans=i-1-st.top();
//         st.push(i-1);
//         return ans;
//     }
// };

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */