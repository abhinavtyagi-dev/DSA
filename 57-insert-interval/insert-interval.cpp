class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int minf=newInterval[0];
        int maxl=newInterval[1];
        int n=intervals.size();
        int i=0;
        vector<vector<int>>ans;
        while (i<n&&intervals[i][0]<newInterval[0]&&intervals[i][1]<newInterval[0]){
            vector<int>temp;
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i][1]);
            ans.push_back(temp);
            i++;
        }
        while (i<n&&intervals[i][0]<=maxl){
            maxl=max(intervals[i][1],maxl);
            minf=min(intervals[i][0],minf);
            i++;
        }
        vector<int>temp1;
            temp1.push_back(minf);
            temp1.push_back(maxl);
            ans.push_back(temp1);
        while (i<n&&intervals[i][0]>newInterval[1]&&intervals[i][1]>newInterval[1]){
            vector<int>temp;
            temp.push_back(intervals[i][0]);
            temp.push_back(intervals[i][1]);
            ans.push_back(temp);
            i++;
        }
         return ans;   
    }
};