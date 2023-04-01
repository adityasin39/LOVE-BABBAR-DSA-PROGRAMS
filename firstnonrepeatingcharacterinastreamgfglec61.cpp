  string ans="";
		    vector<int> count(26,0);
		    queue<int> q;
		    for(int i=0;i<A.size();i++)
		    {
		        q.push(A[i]);
		        count[A[i]-'a']++;
		        while( !q.empty() && count[q.front()-'a']>1) q.pop();
		        if(!q.empty()) ans+=q.front();
		        else ans+='#';
		    }
		    return ans;
		}