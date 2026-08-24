class Solution {
public:
int findprofit(vector<int>& prices,int ind,int buy,int k, vector<vector<vector<int>>>& dp){
        int n=prices.size();
         if (ind==n){
            return 0;
        }
        if (k>1){
            return 0;
        }
       if (dp[ind][buy][k]!=-1){
          return dp[ind][buy][k];
       }
       
        int profit=0;
        if (buy){
            profit=max(-prices[ind]+findprofit(prices,ind+1,0,k,dp),findprofit(prices,ind+1,1,k,dp));
        }
        else{
            profit+=max(prices[ind]+findprofit(prices,ind+1,1,k+1,dp),findprofit(prices,ind+1,0,k,dp));
        }
        dp[ind][buy][k]=profit;
        
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
         vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        int ans=findprofit(prices,0,1,0,dp);
        return ans;
    }
};