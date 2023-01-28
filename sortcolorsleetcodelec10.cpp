// This is called the dutch flag algorithm.
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int nextZero=0;
        int nextTwo=n-1;
        while(i<=nextTwo)
        {
            if(nums[i]==0)
            {
                swap(nums[i],nums[nextZero]);
                i++;
                nextZero++;
            }
            else if(nums[i]==2)
            {
                swap(nums[i],nums[nextTwo]);
                nextTwo--;
            }
            else
            {
                i++;
            }
        }
    }
};