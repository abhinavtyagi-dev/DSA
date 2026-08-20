class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
         vector<vector<int>> dp(n+1,vector<int>(m+1,0));
         for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                int match=0,notmatch=0;
                if (word1[i]==word2[j]){
                    match=1+dp[i][j];
                }
                else{
                    int notmatch1=dp[i+1][j];
                    int notmatch2=dp[i][j+1];
                    notmatch=max(notmatch1,notmatch2);
                }
                dp[i+1][j+1]=match+notmatch;
            }
         }
         return (n-dp[n][m])+(m-dp[n][m]);
    }
};