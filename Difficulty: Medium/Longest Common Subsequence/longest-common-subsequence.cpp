class Solution {
  public:
    int lcs(string &s1, string &s2) {
    int n=s1.size(),m=s2.size();
     vector<vector<int>> dp(n+1,vector<int>(m+1,0));
     for (int i=0;i<n;i++){
         for (int j=0;j<m;j++){
             int match=0,notmatch=0;
             if (s1[i]==s2[j]){
             match=1+dp[i][j];
             }
             else{
                 int notmatch1=dp[i][j+1];
                 int notmatch2=dp[i+1][j];
                 notmatch=max(notmatch1,notmatch2);
             }
             dp[i+1][j+1]=notmatch+match;
         }
     }
     return dp[n][m];
        
    }
};
