class Solution {
public:
int cnt=0;
long long nocoins(vector<int>& coins,int k,int ind,vector<vector<long long>>& dp){
    
    if (k==0){
       
        return 0;
    }
    if (ind<0){
        return INT_MAX;
    }
   
    if (dp[ind][k]!=-1){
        return dp[ind][k];
    }
    long long nottake=INT_MAX,take=INT_MAX;
    nottake=nocoins(coins,k,ind-1,dp);
    if (coins[ind]<=k){
        take=1+nocoins(coins,k-coins[ind],ind,dp);
    }
    dp[ind][k]=min(nottake,take);
    return dp[ind][k];
}
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<long long>>dp(n,vector<long long>(amount+1,-1));
        long long ans=nocoins(coins,amount,n-1,dp);
        if (ans>=INT_MAX){
            return -1;
        }
        return ans;
    }
};