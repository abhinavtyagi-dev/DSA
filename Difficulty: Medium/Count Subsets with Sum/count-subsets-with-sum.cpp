class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        dp[0][0]=1;
        if (arr[0]==0){
            dp[0][0]=2;
        }
        else {
            if (arr[0]<=target){
            dp[0][arr[0]]=1;
            }
        }
        for (int i=1;i<n;i++){
            
            for (int j=0;j<=target;j++){
                int nottake=dp[i-1][j];
                int take=0;
                if (arr[i]<=j){
                    take=dp[i-1][j-arr[i]];
                }
                dp[i][j]=take+nottake;
            }
        }
        return dp[n-1][target];
    }
};