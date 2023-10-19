// sc O(n)
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n=height.size();
//         if(n<=2) return 0;
//         vector<int> maxLeft(n,0);
//         maxLeft[1]=height[0];
//         vector<int> maxRight(n,0);
//         maxRight[n-2]=height[n-1];
//         for(int i=2;i<n-1;i++) maxLeft[i]=max(height[i-1],maxLeft[i-1]);
//         for(int i=n-3;i>=1;i--) maxRight[i]=max(height[i+1],maxRight[i+1]);
//         int ans=0;
//         for(int i=1;i<n-1;i++)
//         {
//             int trapped=min(maxLeft[i],maxRight[i])-height[i];
//             if(trapped<=0) continue;
//             else ans+=trapped;
//         }
//         return ans;
//     }
// };
// sc=O(1)
// if you dont understand then refer to AndresValdes solution
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<=2) return 0;
        int left=0;
        int right=n-1;
        int maxLeft=0;
        int maxRight=0;
        int ans=0;
        while(left<=right)
        {
            if(height[left]<=height[right])
            {
                if(height[left]>maxLeft) maxLeft=height[left];
                else ans+=maxLeft-height[left];
                left++;
            }
            else
            {
                if(height[right]>maxRight) maxRight=height[right];
                else ans+=maxRight-height[right];
                right--;
            }
        }
        return ans;
    }
};