class Solution {
  public:
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
      vector<pair<pair<int,int>,int>> store;
      for (int i=0;i<s.size();i++){
          store.push_back({{f[i],i+1},s[i]});
      }
      sort(store.begin(),store.end());
      int nexttime=-1;
      vector<int>ans;
      for (int i=0;i<store.size();i++){
         auto it=store[i];
         if (it.second>nexttime){
             ans.push_back(it.first.second);
             nexttime=it.first.first;
         }
         
      }
      sort(ans.begin(),ans.end());
      return ans;
    }
};