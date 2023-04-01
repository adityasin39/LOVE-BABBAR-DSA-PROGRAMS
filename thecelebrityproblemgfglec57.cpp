// one more approach is available which is two pointers with TC=O(n) and SC=O(1)
//Create two indices i and j, where i = 0 and j = n-1
//Run a loop until i is less than j.
//Check if i knows j, then i can't be a celebrity. so increment i, i.e. i++
//Else j cannot be a celebrity, so decrement j, i.e. j--
//Assign i as the celebrity candidate
//Now at last check that whether the candidate is actually a celebrity by re-running a loop from 0 to n-1  and constantly checking that if the candidate knows a person or if there is a candidate who does not know the candidate, then we should return -1. else at the end of the loop, we can be sure that the candidate is actually a celebrity.
// a stack approach TC=O(n) and SC=O(n) 
class Solution 
{
    bool knows(int a, int b, vector<vector<int> >& M)
    {
        if(M[a][b]==1) return true;
        else return false;
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        
        // put all people into the stack
        stack<int> st;
        for(int i=0;i<n;i++) st.push(i);
        while(st.size()!=1){ // take two people and check whether they know each other, finally only one person will
        // be left and he can be a potential celeb
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();
        if(knows(a,b,M)) st.push(b);
        else if(knows(b,a,M)) st.push(a);
        
        }
        // now we have to check if the potential celeb is actually a celeb
        int celeb=st.top();
        int zerocnt=0;
        for(int i=0;i<n;i++)
        {
            if(M[celeb][i]==0) zerocnt++;
        }
        if(zerocnt!=n) return -1;
        int onecnt=0;
        for(int i=0; i<n;i++)
        {
            if(M[i][celeb]==1) onecnt++;
        }
        if(onecnt!=n-1) return -1;
        return celeb;
    }
};
// Brute force with O(n*n) and SC=O(1)
// class Solution 
// {
//     public:
//     //Function to find if there is a celebrity in the party or not.
//     int celebrity(vector<vector<int> >& M, int n) 
//     {
        
//         for(int i=0;i<n;i++)
//         {
//             int count=0;
//             for(int j=0;j<n;j++)
//             {
//                 if(M[i][j]==0) count++;
//             }
//             if(count==n) 
//             {
//                 int k;
//                 for( k=0;k<n;k++)
//                 {
//                     if(k==i) continue;
//                     if(k!=i && M[k][i]==0) break;
//                     else continue;
//                 }
//                 if(k==n) return i;
//             }
//         }
//         return -1;
//     }
// };