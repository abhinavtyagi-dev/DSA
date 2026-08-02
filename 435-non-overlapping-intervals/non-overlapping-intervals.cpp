class Solution {
public:
    void removeint( vector<pair<int,int>>&store,int& cnt){
        int nexttime=INT_MIN;
        for (int i=0;i<store.size();i++){
            if (store[i].second>=nexttime){
                nexttime=store[i].first;
            }
            else{
                cnt++;
            }
        }
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      vector<pair<int,int>>store;
      for (int i=0;i<intervals.size();i++){
        int st=intervals[i][0];
        int ft=intervals[i][1];
        store.push_back({ft,st});
      }
      sort(store.begin(),store.end());
      int cnt=0;
      removeint(store,cnt);
      return cnt;
    }
};