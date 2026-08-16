class Solution {
  public:
    int findsum(vector<int>& val,vector<int>& wt,int k,int ind,vector<vector<int>>& dp){
        if (k<0){
            return 0;
        }
        if (ind==0){
            if (wt[0]<=k){
                return val[0];
            }
            else {
                return 0;
            }
        }
        if (dp[ind][k]!=-1){
            return dp[ind][k];
        }
        
        int nottake=INT_MIN,take=INT_MIN;
        nottake=findsum(val,wt,k,ind-1,dp);
        if (wt[ind]<=k){
            take=val[ind]+findsum(val,wt,k-wt[ind],ind-1,dp);
        }
        dp[ind][k]=max(take,nottake);
        return dp[ind][k];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n=val.size();
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       int ans=findsum(val,wt,W,n-1,dp);
       return ans;
        
    }
};