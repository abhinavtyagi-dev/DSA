class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
            int n=s1.size(),m=s2.size();
            int maxi=0;
            vector<vector<int>>dp(n+1,vector<int>(m+1,0));
            for (int i=0;i<n;i++){
                for (int j=0;j<m;j++){
                    if (s1[i]==s2[j]){
                        dp[i+1][j+1]=1+dp[i][j];
                        maxi=max(maxi,dp[i+1][j+1]);
                    }
                }
            }
        return maxi;
    }
};