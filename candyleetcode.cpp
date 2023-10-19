//best approach
// Do it in two directions.
// The first loop makes sure children with a higher rating get more candy than its left neighbor; the second loop makes sure children with a higher rating get more candy than its right neighbor.
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> candies(n,1);
        for(int i=1;i<n;i++) if(ratings[i]>ratings[i-1]) candies[i]=candies[i-1]+1;
        for(int i=n-1;i>=1;i--) if(ratings[i-1]>ratings[i]) candies[i-1]=max(candies[i-1],candies[i]+1);
        int ans=accumulate(candies.begin(),candies.end(),0);
        return ans;
    }
};
//brute force
// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         if(ratings.size()==1) return 1;
//         vector<int> candies(ratings.size(),1);
//         multimap<int,vector<int>> neighbours;
//         for(int i=0;i<ratings.size();i++)
//         {
//             if(i==0) neighbours.insert({ratings[i],vector<int>{INT_MAX,ratings[i+1],i}});
//             else if(i==(ratings.size()-1)) neighbours.insert({ratings[i],vector<int>{ratings[i-1],INT_MAX,i}});
//             else neighbours.insert({ratings[i],vector<int>{ratings[i-1],ratings[i+1],i}});   
//         }
//         for(auto it:neighbours)
//         {
//             vector<int> temp=it.second;
//             int left=temp[0];
//             int right=temp[1];
//             int index=temp[2];
//             int curr=it.first;
//             if(index==0)
//             {
//                 if(curr>right) candies[0]=candies[1]+1;
//             }
//             else if(index==(ratings.size()-1))
//             {
//                 if(curr>left) candies[ratings.size()-1]=candies[ratings.size()-2]+1;
//             }
//             else{
//             if((curr>left) && (curr>right)) candies[index]=max(candies[index-1],candies[index+1])+1;
//             else if(curr>left) candies[index]=candies[index-1]+1;
//             else if(curr>right) candies[index]=candies[index+1]+1;
//             }
//         }
//         int ans=0;
//         for(int i=0;i<candies.size();i++) ans+=candies[i];
//         return ans;
//     }
// };