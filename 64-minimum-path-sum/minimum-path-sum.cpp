class Solution {
    int maxsum=INT_MIN;
    int minsum(vector<vector<int>>& mat,int r,int c,vector<vector<int>>& dp){
        if(dp[r][c]!=-1){
            return dp[r][c];
        }

        int dr=-1,dc=-1;
        int up=INT_MAX,left=INT_MAX;
        if (r+dr>=0){
            if (up==INT_MAX){
                up=0;
            }
             up+=minsum(mat,r+dr,c,dp);
        }
        if (c+dc>=0){
             if (left==INT_MAX){
                left=0;
            }
         left+=minsum(mat,r,c+dc,dp);
        }
        dp[r][c]=mat[r][c]+min(up,left);
        return dp[r][c];
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[0][0]=grid[0][0];
        int ans=minsum(grid,n-1,m-1,dp);
        return ans;
    }
};

// you can move in the four direction