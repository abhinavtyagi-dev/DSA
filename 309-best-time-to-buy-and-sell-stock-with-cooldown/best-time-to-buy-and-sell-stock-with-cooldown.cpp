class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();// isme yrr do row chiye hongi hme last wali do
        vector<vector<int>> prev(2,vector<int>(2,0));

        for (int i=n-1;i>=0;i--){
            vector<int> curr(2,0);
            for (int j=0;j<=1;j++){
                int profit=0;
                if (j){
                    profit=max(-prices[i]+prev[0][0],prev[0][1]);
                }
                else{
                    profit=max(prices[i]+prev[1][1],prev[0][0]);
                }
                curr[j]=profit;

            }
            for (int i=0;i<=1;i++){
                prev[1][i]=prev[0][i];
                prev[0][i]=curr[i];
            }
            
        }
        return prev[0][1];
    }
};