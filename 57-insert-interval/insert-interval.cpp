class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>store;
        for (int i=0;i<intervals.size();i++){
            int s=intervals[i][0];
            int l=intervals[i][1];
            vector<int>temp;
            temp.push_back(s);
            temp.push_back(l);
            store.push_back(temp);
        }
      store.push_back(newInterval);
     sort(store.begin(),store.end());
     int minf=INT_MAX;
        int maxl=INT_MIN;
        vector<vector<int>>ans;
        for (int i=0;i<store.size();i++){
            if (minf==INT_MAX&&maxl==INT_MIN){
                minf=store[i][0];
                maxl=store[i][1];
            }
            else if (store[i][0]>maxl){
                vector<int>temp;
                temp.push_back(minf);
                temp.push_back(maxl);
                ans.push_back(temp);
                minf=store[i][0];
                maxl=store[i][1];
            }
            else{
                 minf=min(store[i][0],minf);
                maxl=max(store[i][1],maxl);
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