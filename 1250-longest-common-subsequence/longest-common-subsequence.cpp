class Solution {
public:
    int findcommon(string& s1,string& s2,int ind1,int ind2,vector<vector<int>>& dp){
        if (ind1<0||ind2<0){
            return 0;
        }
        if (ind1==0&&ind2==0){
            if (s1[ind1]==s2[ind2]){
                return 1;
            }
            else{
                return 0;
            }
        }
        if (dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int match=0,notmatch=0;
        if (s1[ind1]==s2[ind2]){
             match=1+findcommon(s1,s2,ind1-1,ind2-1,dp);
        }
        else{
        int notmatch1=0,notmatch2=0;
         notmatch1=findcommon(s1,s2,ind1-1,ind2,dp);
         notmatch2=findcommon(s1,s2,ind1,ind2-1,dp);
         notmatch=max(notmatch1,notmatch2);
        }
        dp[ind1][ind2]=notmatch+match;
        return dp[ind1][ind2];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(),m=text2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=findcommon(text1,text2,n-1,m-1,dp);
        return ans;
 }  
};