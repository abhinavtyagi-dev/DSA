class Solution {
public:
   int findinsert(string& s,int ind1,int ind2,vector<vector<int>>& dp){
   if (ind1>=ind2){
    return 0;
   }
    if (dp[ind1][ind2]!=-1){
        return dp[ind1][ind2];
    }
    int match =0,notmatch=0;
    if (s[ind1]==s[ind2]){
       match=findinsert(s,ind1+1,ind2-1,dp);
    }
    else{
         int notmatch1=1+findinsert(s,ind1+1,ind2,dp);
         int notmatch2=1+findinsert(s,ind1,ind2-1,dp);
         notmatch=min(notmatch1,notmatch2);
    }
    dp[ind1][ind2]=match+notmatch;
    return dp[ind1][ind2];
   }
    int minInsertions(string s) {
        int n=0,m=s.length();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        int ans=findinsert(s,n,m-1,dp);
        return ans;
    }
};