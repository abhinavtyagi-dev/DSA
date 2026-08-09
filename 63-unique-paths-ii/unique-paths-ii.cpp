class Solution {
public:
 int findpaths(vector<vector<int>>& mat,int r,int c,vector<vector<int>>& dp){
   if (dp[r][c]!=-1){
    return dp[r][c];
   }
    if (mat[r][c]==1){
        return 0;
    }
    
    int dr=-1,dc=-1;
    int left=0,up=0;
    if (r+dr>=0){
        left= findpaths(mat,r+dr,c,dp);
    }
    if (c+dc>=0){
       up=findpaths(mat,r,c+dc,dp);
    }
    dp[r][c]=left+up;
     return (left+up);
 }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m= obstacleGrid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        dp[0][0]=1;
        if (obstacleGrid[n-1][m-1]==1||obstacleGrid[0][0]==1){
            return 0;
        }

        int ans=findpaths(obstacleGrid,n-1,m-1,dp);
        return ans;
    }
};