class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(2,vector<long long>(3,0)));
         for (int i=n-1;i>=0;i--){
            for (int j=0;j<=1;j++){
                for (int k=0;k<=1;k++){
                     long long profit=0;
        if (j){
           profit=max(-prices[i]+dp[i+1][0][k],dp[i+1][1][k]);
        }
        else{
           
           profit=max(prices[i]+dp[i+1][1][k+1],dp[i+1][0][k]);
            
        }
        dp[i][j][k]=profit;
        
        
                }
            }
         }
         return (int)dp[0][1][0];
    }
};