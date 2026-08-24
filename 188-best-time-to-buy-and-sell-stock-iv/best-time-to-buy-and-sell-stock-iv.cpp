class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
          int n=prices.size();
         vector<vector<vector<long long>>> dp(n+1,vector<vector<long long>>(2,vector<long long>(k+1,0)));
         for (int i=n-1;i>=0;i--){
            for (int j=0;j<=1;j++){
                for (int l=0;l<k;l++){
                     long long profit=0;
        if (j){
           profit=max(-prices[i]+dp[i+1][0][l],dp[i+1][1][l]);
        }
        else{
           
           profit=max(prices[i]+dp[i+1][1][l+1],dp[i+1][0][l]);
            
        }
        dp[i][j][l]=profit;
        
        
                }
            }
         }
         return (int)dp[0][1][0];
    }
};