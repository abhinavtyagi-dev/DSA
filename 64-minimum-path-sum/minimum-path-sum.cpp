class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        dp[0][0]=grid[0][0];
        for (int i=1;i<m;i++){
            dp[0][i]=grid[0][i]+dp[0][i-1];
             }
             int dr=-1,dc=-1;
        for (int i=1;i<n;i++){
            for (int j=0;j<m;j++){
                int up=INT_MAX,left=INT_MAX;
                if (i+dr>=0){
                    if (up==INT_MAX){
                        up=0;
                    }
                    up+=dp[i+dr][j];
                }
                if (j+dc>=0){
                    if (left==INT_MAX){
                        left=0;
                    }
                    left+=dp[i][j+dc];
                }
                dp[i][j]=grid[i][j]+min(up,left);
            }
        }
        return dp[n-1][m-1];
    }
};