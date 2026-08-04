class Solution {
  public:
    int solve(vector<int>& bt) {
        vector<int>store;
        sort(bt.begin(),bt.end());
        int wtime=0;
        store.push_back(0);
        for (int i=1;i<bt.size();i++){
            wtime+=bt[i-1];
            store.push_back(wtime);
        }
        int sum=0;
        for (int i=0;i<store.size();i++){
            sum+=store[i];
        }
        return (sum)/bt.size();
    }
};