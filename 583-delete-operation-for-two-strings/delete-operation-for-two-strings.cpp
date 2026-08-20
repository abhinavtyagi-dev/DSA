class Solution {
public:
    int minDistance(string word1, string word2) {
          int n=word1.size(),m=word2.size();
        vector<int> dp(m+1,0);
      
        for (int i=0;i<n;i++){
            vector<int> curr(m+1,0);
            for (int j=0;j<m;j++){
                int notmatch=0,match=0;
                if (word1[i]==word2[j]){
                    match=1+dp[j];
                }
                else{
                    int notmatch1=curr[j];
                    int notmatch2=dp[j+1];
                    notmatch=max(notmatch1,notmatch2);
                }
                curr[j+1]=match+notmatch;
            }
            dp=curr;
        }
        return (n-dp[m])+(m-dp[m]);
    }
};