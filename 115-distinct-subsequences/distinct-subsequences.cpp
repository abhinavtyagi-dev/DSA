class Solution {
public:
    int numDistinct(string s, string t) {
        int mod=1e9+7;
        int n=s.size(),m=t.size();
        vector<long long> dp(m+1,0);
        dp[0]=1;
        for (int i=0;i<n;i++){
            for (int j=m-1;j>=0;j--){
                long long match1=0,match2=0;
                long long notmatch=0;
                if (s[i]==t[j]){
                    match1+=(dp[j])%mod;
                    match2+=(dp[j+1])%mod;
                }
                else{
                    notmatch+=(dp[j+1])%mod;
                }
                dp[j+1]=(notmatch+match1+match2)%mod;
            }
        }
        return (int)dp[m];
    }
};