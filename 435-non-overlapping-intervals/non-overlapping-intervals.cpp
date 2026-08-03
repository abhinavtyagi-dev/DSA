class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int nexttime=INT_MIN;
        int cnt=0;
        for (int i=0;i<intervals.size();i++){
            if (intervals[i][0]<nexttime){
                cnt++;
                if (nexttime==INT_MIN){
                    nexttime=intervals[i][1];
                }
                else{
                    if (intervals[i][1]<nexttime){
                        nexttime=intervals[i][1];
                    }
                }

            }
            else{
                nexttime=intervals[i][1];
            }
        }
        return cnt;
    }
};