 int n=s.size();
		    vector<string> ans;
		    for(int i=1;i<(1<<n);i++) //1<<n =2^n
		    {
		       string sub="";
		       for(int j=n-1;j>=0;j--)
		       {
		           if(((1<<j)&i)!=0) sub+=s[n-1-j]; // always put ) after i as & has more precedence than !=
		       }
		       ans.push_back(sub);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;