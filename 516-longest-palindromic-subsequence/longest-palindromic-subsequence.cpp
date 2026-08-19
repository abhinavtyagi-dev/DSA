class Solution {
public:
int longestpallin(string& s,int ind1,int ind2,vector<vector<int>>& dp){
       if (ind1>ind2){
           return 0;
       }
       if (ind1==ind2){
           return 1;
       }
       if (dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
       }
       int match=0,notmatch=0;
       if (s[ind1]==s[ind2]){
           match=2+longestpallin(s,ind1+1,ind2-1,dp);
       }
       else{
           int notmatch1=longestpallin( s,ind1+1,ind2,dp);
             int notmatch2=longestpallin( s,ind1,ind2-1,dp);
           notmatch=max(notmatch1,notmatch2);
       }
       dp[ind1][ind2]=match+notmatch;
       return (match+notmatch);
   }
    int longestPalindromeSubseq(string s) {
          int n=0,m=s.length();
          vector<vector<int>> dp(m,vector<int>(m,-1));
       int ans=longestpallin(s,n,m-1,dp);
       return ans;
    }
};