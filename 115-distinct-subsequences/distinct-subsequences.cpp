class Solution {
public:
    int findt(string& s,string& t,int ind1,int ind2,vector<vector<int>>& dp){
        if (ind2<0){
            return 1;
        }
        if (ind1<0){
            return 0;
        }

        if (dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
          int match1=0,match2=0;
          int notmatch=0;
          if (s[ind1]==t[ind2]){
              match1+=findt(s,t,ind1-1,ind2-1,dp);
              match2+=findt(s,t,ind1-1,ind2,dp);
          }
          else{
             notmatch+=findt(s,t,ind1-1,ind2,dp);
          }
          dp[ind1][ind2]=match1+match2+notmatch;
          return dp[ind1][ind2];
    }
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=findt(s,t,n-1,m-1,dp);
        return ans;
    }
};