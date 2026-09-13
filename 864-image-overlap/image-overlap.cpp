class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> store1;
        vector<pair<int,int>> store2;
        for (int i=0;i<img1.size();i++){
            for (int  j=0;j<img1[0].size();j++){
                if (img1[i][j]==1){
                    store1.push_back({i,j});
                }
                if (img2[i][j]==1){
                    store2.push_back({i,j});
                }
            }
        }
        map<pair<int,int>,int> mpp;
        for (int i=0;i<store1.size();i++){
            for (int j=0;j<store2.size();j++){
                int dr=store1[i].first-store2[j].first;
                int dc=store1[i].second-store2[j].second;
                mpp[{dr,dc}]++;
            }
        }
        int cnt=0;
        for (auto it:mpp){
            cnt=max(cnt,it.second);
        }
        return cnt;
    }
};                                                                                               