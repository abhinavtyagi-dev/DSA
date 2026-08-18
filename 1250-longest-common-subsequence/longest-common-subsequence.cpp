class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<int>dp(m,0);
        for (int i=0;i<m;i++){
            if (text2[i]==text1[0]){
                dp[i]=1;
            }
            else{
                if(i!=0){
                    dp[i]=dp[i-1];
                }
            }
        }
        
        for (int i=1;i<n;i++){
            vector<int>curr(m,0);
            for (int j=0;j<m;j++){
                int match=0,notmatch=0;
                if (text1[i]==text2[j]){
                if (j!=0){
                    match=1+dp[j-1];
                }
                else{
                    match=1;
                }
            }
            else{
                  int notmatch1=0,notmatch2=0;
                 notmatch1=dp[j];
                if (j!=0){
                    notmatch2=curr[j-1];
                }
                notmatch=max(notmatch1,notmatch2);
            }
            curr[j]=notmatch+match;
            }
            dp=curr;
        }
        return dp[m-1];
    }
};