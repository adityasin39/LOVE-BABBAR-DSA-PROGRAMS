//TC=O(n) and SC=O(1)
    // in this approach, jab bhi hume koi positive number milta hai tab ham uss number ke index(ans wale index jaha count store karna hai)
    // pe jaake -1 daal dete hai 1 is for count and - isliye daal rahe hai taaki actual array numbers se differentiate kar paayein.
    // but -1 daalne pe woh count wale index wala number lose ho jaayega isliye use abhi wale index pe daal denge phir iss number ko check karenge.
    //agar count wale index par negative number hai matlab already woh number mil chuka hai aur ab waapas mila hai so to increase the count we decrement -1.
    // Also ham iss wale number ke jagah 0 kar denge taaki yeh kisi dusre position pe jaake phir count naa ho jaaye taaki ham ise ignore kar sake as it is already included.
    // agar negative hai ya out of N hai toh we ignore.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        int i=0;
        while(i<N)
        {
            if(arr[i]>N || arr[i]<0)
            {
                i++;
                continue;
            }
            int index=arr[i]-1;
            if(arr[index]>0)
            {
                arr[i]=arr[index];
                arr[index]=-1;
            }
            else
            {
                arr[index]--;
                arr[i]=0; 
                i++;
            }
        }
        for(int i=0;i<N;i++)
        {
            if(arr[i]<0)
            arr[i]=-arr[i];
            else arr[i]=0; //agar yeh nahi daala aur sirf arr[i]=-arr[i] likha toh arr[i]=0 wale case mein ajeeb answer aata hai.
        }
    }
    //Approach 2 TC=O(n) Sc=O(n)
    // void frequencyCount(vector<int>& arr,int N, int P)
    // { 
    //     vector<int> hash(N+1,0); // N+1 size ka banega not P+1 because if P is less than N then the numbers between P and N wont have their count and will give segmentation fault.
    //     for(int i=0;i<N;i++)
    //     {
    //         if(arr[i]<=N)
    //         hash[arr[i]]++;
    //     }
    //     for(int i=1;i<=N;i++)
    //     {
    //         arr[i-1]=hash[i];
    //     }
    // }