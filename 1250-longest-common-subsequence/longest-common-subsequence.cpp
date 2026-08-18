class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for (int i=0;i<m;i++){
            if (text1[0]==text2[i]){
                dp[0][i]=1;
            }
            else{
                if (i!=0){
                dp[0][i]=dp[0][i-1];
                }
            }
        }
        for (int i=1;i<n;i++){
            for (int j=0;j<m;j++){
                int match=0,notmatch=0;
                if (text1[i]==text2[j]){
                if (j!=0){
                    match=1+dp[i-1][j-1];
                }
                else{
                    match=1;
                }
            }
            else{
                  int notmatch1=0,notmatch2=0;
                 notmatch1=dp[i-1][j];
                if (j!=0){
                    notmatch2=dp[i][j-1];
                }
                notmatch=max(notmatch1,notmatch2);
            }
            dp[i][j]=notmatch+match;
            }
        }
        return dp[n-1][m-1];
    }
};