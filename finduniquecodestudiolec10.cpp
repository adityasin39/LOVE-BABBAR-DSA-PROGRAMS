//here, i have listed down two solutions . The first one is brute force and the second one is kadak dimag wala solution.
//1st approach.
int findUnique(int arr[], int size)
{
    int i,j;
    for( i=0;i<size;i++)
    {
        for( j=0;j<size;j++)
        {
            if(arr[i]==arr[j] && i!=j)
            {
              
                break;
            }
        }
        if(j==size)
            return arr[i];
    }
}
//2nd approach.
int findUnique(int arr[], int size)
{
    int ans=arr[0];
    for(int i=1;i<size;i++)
    {
        ans=ans^arr[i];//the logic here is that a number xored with the same number gives 0 and 0 xored with a number gives the same number itself. if the array is for eg 1 3 4 4 3 then jaise bachpan mein maths mein sikha tha ki 1+3+4-4-3 ka answer 1 hoga so in this way we get the unique element and thus here we have used xor to implement the same bachpan wala logic.n^n=0 and n^0=n.
        
    }
    return ans;
}