class Solution {
public:
   int findcherry(vector<vector<int>>& mat,     vector<vector<vector<int>>>& dp,int i,int j1,int j2){
    int n=mat.size(),m=mat[0].size();
    if (j1<0||j1>=m||j2<0||j2>=m){
        return INT_MIN;
    }
    if (i==n-1){
        if (j1==j2){
            return mat[i][j1];
        }
        else{
            return (mat[i][j1]+mat[i][j2]);
        }
    }
    if (dp[i][j1][j2]!=-1){
        return dp[i][j1][j2];
    }
       int maxi=0;
       for (int i1=-1;i1<=1;i1++){
        for (int j=-1;j<=1;j++){
            int ans=0;
            if (j1==j2){
              ans=mat[i][j1]+findcherry(mat,dp,i+1,j1+i1,j2+j);
            }
            else{
                   ans=mat[i][j1]+mat[i][j2]+findcherry(mat,dp,i+1,j1+i1,j2+j);
            }
            maxi=max(maxi,ans);
        }

       }
       dp[i][j1][j2]=maxi;
       return maxi;
      
    
   }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
     vector<vector<vector<int>>> dp(n,
            vector<vector<int>>(m, vector<int>(m, -1)));
            int ans=findcherry(grid,dp,0,0,m-1);
            return ans;
        }
};