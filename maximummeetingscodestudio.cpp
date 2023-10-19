int maximumMeetings(vector<int> &start, vector<int> &end)
{
     vector<pair<int,int>> intervals;
     for(int i=0;i<start.size();i++)
     {
         intervals.push_back({end[i],start[i]});
     }
     sort(intervals.begin(),intervals.end());
     int cnt=1;
     int last=intervals[0].first;
     for(int i=1;i<start.size();i++)
     {
         if(intervals[i].second>last)
         {
             cnt++;
             last=intervals[i].first;
         }
     }
     return cnt;
}