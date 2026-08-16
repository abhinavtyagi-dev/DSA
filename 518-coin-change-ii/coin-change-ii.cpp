class Solution {
public:
    int noofsum(vector<int>& coins,int k,int ind,vector<vector<int>>& dp){
        if (k==0){
            return 1;
        }
        if (ind==0){
            if (k>=coins[0]){
                if (k%coins[0]==0){
                    return 1;
                }
                else{
                return 0;
            }
            }
            else{
                return 0;
            }
            
        }
            if (dp[ind][k]!=-1){
                return dp[ind][k];
            }
            int nottake=0,take=0;
            nottake+=noofsum(coins,k,ind-1,dp);
            if (coins[ind]<=k){
                take+=noofsum(coins,k-coins[ind],ind,dp);
            }
            dp[ind][k]=nottake+take;
            return dp[ind][k];
        
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans=noofsum(coins,amount,n-1,dp);
        return ans;
    }
};