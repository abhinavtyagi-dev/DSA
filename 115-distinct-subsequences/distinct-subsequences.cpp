class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        int mod=1e9+7;
        for (int i=0;i<n;i++){
            dp[i][0]=1;

        }
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                long long match1=0,match2=0;
                long long notmatch=0;
                if (s[i]==t[j]){
                    match1+=(dp[i][j])%mod;
                    match2+=(dp[i][j+1])%mod;
                }
                else{
                    notmatch+=(dp[i][j+1])%mod;
                }
                dp[i+1][j+1]=(match1+match2+notmatch)%mod;
            }
        }
        return (int)dp[n][m];
    }
};