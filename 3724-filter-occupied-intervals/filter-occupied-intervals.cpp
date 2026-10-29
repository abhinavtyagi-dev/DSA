
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(
        vector<vector<int>>& occupiedIntervals,
        int freeStart, int freeEnd) {

        int n = occupiedIntervals.size();

        vector<pair<int,int>> store;

        for (int i = 0; i < n; i++) {
            store.push_back({
                occupiedIntervals[i][0],
                occupiedIntervals[i][1]
            });
        }

        sort(store.begin(), store.end());

        vector<pair<int,int>> ans;

        if (n == 0) return {};

        int stind = store[0].first;
        int lind = store[0].second + 1;

        for (int i = 1; i < n; i++) {
            if (store[i].first > lind) {
                ans.push_back({stind, lind - 1});

                stind = store[i].first;
                lind = store[i].second + 1;
            }
            else {
                if (store[i].second >= lind) {
                    lind = store[i].second + 1;
                }
            }
        }

        ans.push_back({stind, lind - 1});

        vector<vector<int>> ans1;

        for (int i = 0; i < ans.size(); i++) {
            int l = ans[i].first;
            int r = ans[i].second;

            // No overlap with the free interval
            if (r < freeStart || l > freeEnd) {
                ans1.push_back({l, r});
            }
            else {
                // Keep the left part, if it exists
                if (l < freeStart) {
                    ans1.push_back({l, freeStart - 1});
                }

                // Keep the right part, if it exists
                if (r > freeEnd) {
                    ans1.push_back({freeEnd + 1, r});
                }
            }
        }

        return ans1;
    }
};
