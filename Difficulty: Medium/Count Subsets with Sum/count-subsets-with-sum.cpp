class Solution {
  public:
    int findsum(vector<int>& arr, vector<vector<int>>& dp,int ind,int k){
      if (ind==0&&k==0&&arr[0]==0){
          return 2;
      }
      else if (ind==0&&k==0){
          return 1;
      }
        else if (ind==0){
            if (arr[0]==k){
                return 1;
        }
        else{
            return 0;
        }
        
    }
    if (dp[ind][k]!=-1){
        return dp[ind][k];
    }
    int nottake=findsum(arr,dp,ind-1,k);
    int take=0;
    if (arr[ind]<=k){
        take=findsum(arr,dp,ind-1,k-arr[ind]);
    }
    dp[ind][k]=take+nottake;
    return take+nottake;
    }
    int perfectSum(vector<int>& arr, int target) {
        int n =arr.size();
      vector<vector<int>> dp(n,vector<int> (target+1,-1));
      int ans=findsum(arr,dp,n-1,target);
      return ans;
        
    }
};