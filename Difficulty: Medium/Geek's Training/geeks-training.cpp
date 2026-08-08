class Solution {
  public:
    int findmax(vector<vector<int>>& mat,int r,int prev,vector<vector<int>>&dp){
       if (dp[r][prev]!=-1){
           return dp[r][prev];
       }
       int maxi=0;
       if (r==0){
         for (int i=0;i<3;i++){
             if (i!=prev){
                 int curr=mat[r][i];
                 maxi=max(maxi,curr);
             }
            
         }
         return maxi;
       }
        int curr=0;
        int maxcurr=INT_MIN;
        for (int i=0;i<3;i++){
            
            if (i!=prev){
            maxcurr=max(maxcurr,mat[r][i]+findmax(mat,r-1,i,dp));
        }
        }
        dp[r][prev]=maxcurr;
       return maxcurr;
    }
    int maximumPoints(vector<vector<int>>& mat) {
        int n =mat.size();
       vector<vector<int>>dp(n,vector<int>(3,-1));
        int maxpoint=INT_MIN;
        for (int i=0;i<3;i++){
            maxpoint=max(maxpoint,mat[n-1][i]+findmax(mat,n-2,i,dp));
        }
        return maxpoint;
    }
};

// max we have to see and we also have to think about the alternative