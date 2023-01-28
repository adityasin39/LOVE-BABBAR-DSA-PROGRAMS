//Approach 1 which is a brute force one with extra space.
#include <bits/stdc++.h> 
string replaceSpaces(string &str){
    string temp="";
	for(int i=0;i<str.size();i++)
    {
        if(str[i]==' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else temp.push_back(str[i]);
    }
    return temp;
}
// Approach 2 with extra space.
#include <bits/stdc++.h> 
string replaceSpaces(string &str){
    int j=0;
    int n=str.size();
    int i=0;
    string ans="";
    while(j<n)
    {
        while(j<n && str[j]!=' ') j++;
        ans+= str.substr(i,j-i);
       if(j<n) {
      ans+="@40";
        }
       j++;
       i=j;
        }
return ans;
}
//Approach 3 which is the best one and in-place
#include <bits/stdc++.h> 
string replaceSpaces(string &str){
    int spacecount=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]==' ') spacecount++;
    }
    str.resize(str.size()+spacecount*2);// if the size is increased and no character to be added is mentioned then null characters are stored.
    int idx=str.size()-1;
    int r=idx;
    while(idx>=0)
    {
        while(str[idx]=='\0') idx--;
        while(idx>=0 && str[idx]!=' ') str[r--]=str[idx--];
        if(r>=0)
        {
            
        
        str[r--]='0';
        str[r--]='4';
        str[r--]='@';
        }
        idx--;
        
    }
    return str;
}
//Approach 4
#include <bits/stdc++.h> 
string replaceSpaces(string &str){
 for(int i=0;i<str.size();i++)
 {
     if(str[i]==' ') 
         str.replace(i,1,"@40");
 }
    return str;
}