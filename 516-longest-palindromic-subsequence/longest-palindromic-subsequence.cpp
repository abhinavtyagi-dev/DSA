class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length();
string t = s;
reverse(t.begin(), t.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                int match=0,notmatch=0;
                if (s[i]==t[j]){
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
        return dp[n][n];
    }
};