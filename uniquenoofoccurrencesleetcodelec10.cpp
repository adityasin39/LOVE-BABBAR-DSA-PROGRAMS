// best approach
//Since our values are limited to [-1000, 1000], we can use an array instead of hash set to count occurrences. Then, we //can sort our array and check that no adjacent numbers are the same.
//Here i have listed  down 4 sort of different solutions. Tried but didnt find any brute force solution.
//1st approach.
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
     map<int,int> m;
     set<int> s;
     for(int i=0;i<arr.size();i++)
     {
         m[arr[i]]++;
     }                        //here the logic is that i have inserted the values of the map in a set and as set takes only unique elements so if there would be a repetitive value in the map then it wont go again in the set hence we can compare the size of the set and the map and come to our conclusion.
     int mapsize=m.size();
    for(auto it:m)
    {
        s.insert(it.second);      
    }
if(s.size()==mapsize)return true;
else return false;
    }
};
//2nd approach. similar to 1st but then too a little better.
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       map<int,int> m;
       for(int i=0;i<arr.size();i++)
       {
           m[arr[i]]++;
       } 
      set<int> st;
       for(auto it:m)
       {
        //here the logic is that we will check the count of the values of the map in the set and if the count is 1 or greater then we would directly return false because it would mean that the occurrence was already present and thus not unique and if the count would be 0 the n we would insert in the set and go to the next value in the map repeating the same loop.
           if(st.count(it.second)) return false;
           st.insert(it.second);
       }
       return true;

    }
};
//3rd approach.
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        vector<int> v;
        for(auto it:m)
        {
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i]==v[i+1])return false;
        }
        return true;
    }
};
//4th approach
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> v;
        sort(arr.begin(),arr.end());
        int i=0;
        while(i<arr.size())
        {
            int count=1;
            for(int j=i+1;j<arr.size();j++){

            
            if(arr[j]==arr[i])
            {
                count++;
            }
            else
            break;
            }
            v.push_back(count);
            i=i+count;
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i+1]==v[i])return false;
        }
        return true;
    }
};