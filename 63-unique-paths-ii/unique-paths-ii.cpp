class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if (obstacleGrid[0][0]==1||obstacleGrid[n-1][m-1]==1){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=1;
        int dr=-1,dc=-1;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
              if (obstacleGrid[i][j]==1){
                continue;
              }
              if (i+dr>=0){
                dp[i][j]+=dp[i+dr][j];
              }
              if (j+dc>=0){
                  dp[i][j]+=dp[i][j+dc];
              }

            }
        }
        return dp[n-1][m-1];
    }
};