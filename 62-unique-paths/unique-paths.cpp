class Solution {
    int steps=0;
public:
    int findpaths(int m,int n ,int r,int c,vector<vector<int>>&dp){
        int step=0;
        if (r==m-1&&c==n-1){
            steps+=1;
            return 1;
        }
        if (dp[r][c]!=0){
            steps+=dp[r][c];
            return dp[r][c];
        }
        int dr=1,dc=1;
        if (r+dr<m){
           int val=findpaths(m,n,r+dr,c,dp);
            
             step+=val;
        }
        if (c+dc<n){
            int val=findpaths(m,n,r,c+dc,dp);

                step+=val;
        }
        dp[r][c]=step;
      return step;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;
        int i=0,j=0;
        int ans=findpaths(m,n,i,j,dp);
        return steps;
    }
};