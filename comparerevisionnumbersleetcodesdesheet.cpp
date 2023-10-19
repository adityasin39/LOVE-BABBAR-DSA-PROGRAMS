class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0;
        int j=0;
        int m=version1.size();
        int n=version2.size();
        bool isleading1=true;
        bool isleading2=true;
        while(i<m && j<n)
        {
            while(i<m && isleading1 && version1[i]=='0') i++;
            while(j<n && isleading2 && version2[j]=='0') j++;
            isleading1=false;
            isleading2=false;
            int k=i;
            while(k<m && version1[k]!='.') k++;
            int l=j;
            while(l<n && version2[l]!='.') l++;
            if(i<m && j<n){
            if(version1[i]=='.' && (version2[j]!='0' && version2[j]!='.')) return -1;
            if((version1[i]!='0' && version1[i]!='.') && version2[j]=='.') return 1;
            if(((k-i)>(l-j))) return 1;
            if(((k-i)<(l-j))) return -1;
            if(((k-i)==(l-j)) && version1[i]<version2[j]) return -1;
            if(((k-i)==(l-j)) && version1[i]>version2[j]) return 1;
            if(version1[i]=='.') isleading1=true;
            if(version2[j]=='.') isleading2=true;
            }
            else break;
            i++;
            j++;
        }
        while(i<m)
        {
            if(version1[i]!='0' && version1[i]!='.' ) return 1;
            i++;
        }
        while(j<n)
        {
            if(version2[j]!='0' && version2[j]!='.') return -1;
            j++;
        }
        return 0;
    }
};