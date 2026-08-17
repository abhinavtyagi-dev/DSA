class Solution {
  public:
  int findmax(vector<int>& val,vector<int>& wt,int k,int ind,vector<vector<int>>& dp){
      if (k<=0){
          return 0;
      }
      if (ind==0){
          if (k>=wt[ind]){
              return (val[ind]*(k/wt[ind]));
          }
          else{
              return 0;
          }
      }
      if (dp[ind][k]!=-1){
          return dp[ind][k];
      }
      int take=0,nottake=0;
      nottake=findmax(val,wt,k,ind-1,dp);
      if (k>=wt[ind]){
          take=val[ind]+findmax(val,wt,k-wt[ind],ind,dp);
      }
      dp[ind][k]=max(take,nottake);
      return dp[ind][k];
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n=val.size();
      vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
      int ans=findmax(val,wt,capacity,n-1,dp);
       return ans;
    }
};