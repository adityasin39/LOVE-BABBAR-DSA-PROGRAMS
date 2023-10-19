class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> intToroman;
        intToroman[1]="I";
        intToroman[5]="V";
        intToroman[10]="X";
        intToroman[50]="L";
        intToroman[100]="C";
        intToroman[500]="D";
        intToroman[1000]="M";
        intToroman[4]="IV";
        intToroman[9]="IX";
        intToroman[40]="XL";
        intToroman[90]="XC";
        intToroman[400]="CD";
        intToroman[900]="CM";
        string ans="";
        vector<int> values={1,4,5,9,10,40,50,90,100,400,500,900,1000};
            int i=12;
            while(num!=0 && i>=0){
                if(num/values[i]!=0)
                {
                    int freq=num/values[i];
                    while(freq--) ans+=intToroman[values[i]];
                    num=num%values[i];
                }
                else i--;
            }
            return ans;
    }
};