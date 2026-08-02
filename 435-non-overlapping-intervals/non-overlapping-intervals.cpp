class Solution {
public:
   static bool comp(vector<int>&p1,vector<int>&p2){
    if (p1[1]<p2[1]){
        return true;
    }
    else{
        return false;
    }
   }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        int cnt=0;
        int nexttime=INT_MIN;
        for (int i=0;i<intervals.size();i++){
             if (intervals[i][0]>=nexttime){
                nexttime=intervals[i][1];
             }
             else{
                cnt++;
             }
        }
        return cnt;
    }
};