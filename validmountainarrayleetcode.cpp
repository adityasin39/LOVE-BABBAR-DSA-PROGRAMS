class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        if(n<3) return false;
        while(i+1<n && arr[i]<arr[i+1]) i++;
        if(i==0 || i+1==n || arr[i]==arr[i+1]) return false;
        while(i+1<n && arr[i]>arr[i+1]) i++;
        if(i+1<n) return false;
        return true;
    }
};