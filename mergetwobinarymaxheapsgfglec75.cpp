class Solution{
    public:
    // TC=O(mlogn) SC=O(m)
    void insertion(vector<int>& arr,int& size,int element)
    {
        
        arr.push_back(element);
        int index=arr.size()-1;
        int parentIndex=(index-1)/2;
            while(parentIndex>=0 && arr[parentIndex]<arr[index])
            {
                swap(arr[index],arr[parentIndex]);
                index=parentIndex;
               parentIndex=(index-1)/2;
            }
            
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        for(int i=0;i<m;i++)
        {
            insertion(a,n,b[i]);
        }
        return a;
    }
};