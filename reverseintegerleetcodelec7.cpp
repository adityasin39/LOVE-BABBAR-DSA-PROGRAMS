// class Solution {
// public:
//     int reverse(int x) {
//         long ans=0;
//         while(x){
// ans=(x%10)+ans*10;//ans=ans*10+digit.yaha ans jab int wala limit cross karta tab error milta isliye long use kiya hai.
// x=x/10;}
//     if(ans> pow(2,31)-1 || ans< pow(-2,31))return 0;
//     else return ans;}};
    class Solution {
public:
    int reverse(int x) {
        int ans=0;
        while(x){
            if(ans> (INT_MAX)/10 || ans< (INT_MIN)/10) return 0;
ans=(x%10)+ans*10;
x=x/10;}
     return ans;}};