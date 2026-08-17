class Solution {
  public:
    long long findmax(vector<int>& price,int ind,vector<vector<long long>>& dp,int k){
        if (k==0){
            return 0;
        }
        if (ind==0){
            if (k>=ind+1){
                return (price[0]*(k));
            }
        }
        if (dp[ind][k]!=-1){
            return dp[ind][k];
        }
        long long take=0,nottake=0;
        nottake=findmax(price,ind-1,dp,k);
        if (k>=ind+1){
            take=price[ind]+findmax(price,ind,dp,k-(ind+1));
        }
        dp[ind][k]=max(take,nottake);
        return dp[ind][k];
    }
    
    int cutRod(vector<int> &price) {
        int n=price.size();
        vector<vector<long long>> dp(n,vector<long long>(n+1,-1));
        long long ans=findmax(price,n-1,dp,n);
        return ans;
        
    }
};