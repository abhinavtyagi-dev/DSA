class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>>store;
        int n=intervals.size();
        for (int i=0;i<n;i++){
            int f=intervals[i][0];
            int l=intervals[i][1];
            store.push_back({f,l});
        }
        sort(store.begin(),store.end());
        vector<vector<int>>ans(intervals.size());
        int j=0;
        int minf=INT_MAX;
        int maxl=INT_MIN;
       
        for (int i=0;i<store.size();i++){
            if (minf==INT_MAX&&maxl==INT_MIN){
                minf=store[i].first;
                maxl=store[i].second;
               
            }
            else if (store[i].first>maxl){
                ans[j].push_back(minf);
                ans[j].push_back(maxl);
                 minf=store[i].first;
                maxl=store[i].second;
                
                j++;
            }
         else{
            maxl=max(maxl,store[i].second);
            minf=min(minf,store[i].first);
             
         }


        }
        if (minf!=INT_MAX&&maxl!=INT_MIN){
             ans[j].push_back(minf);
                ans[j].push_back(maxl);
        }
        vector<vector<int>>temp;
        for (int i=0;i<ans.size();i++){
            if (ans[i].empty()){
                break;
            }
            temp.push_back(ans[i]);
        }
        return temp;
    }
};