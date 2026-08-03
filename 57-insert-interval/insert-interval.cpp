class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int minf=INT_MAX;
        int maxl=INT_MIN;
        vector<vector<int>>ans;
        for (int i=0;i<intervals.size();i++){
            if (minf==INT_MAX&&maxl==INT_MIN){
                minf=intervals[i][0];
                maxl=intervals[i][1];
            }
            else if (intervals[i][0]>maxl){
                vector<int>temp;
                temp.push_back(minf);
                temp.push_back(maxl);
                ans.push_back(temp);
                minf=intervals[i][0];
                maxl=intervals[i][1];
            }
            else{
                 minf=min(intervals[i][0],minf);
                maxl=max(intervals[i][1],maxl);
            }
        }
        if (minf!=INT_MIN&&maxl!=INT_MIN){
             vector<int>temp;
                temp.push_back(minf);
                temp.push_back(maxl);
                ans.push_back(temp);
        }
        return ans;
    }
};