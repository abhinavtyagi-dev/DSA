class Solution {
public:
    int convert(string& s1,string& s2,int ind1,int ind2,vector<vector<int>>& dp){
        if (ind1<0&&ind2<0){
            return 0;
        }
        else if (ind1<0){
            return (ind2+1);
        }
        else if(ind2<0){
            return (ind1+1);
        }
        if (dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        
        if (s1[ind1]!=s2[ind2]){
           int notmatch1 =1+convert(s1,s2,ind1-1,ind2-1,dp);
           int notmatch2=1+convert(s1,s2,ind1-1,ind2,dp);
           int notmatch3=1+convert(s1,s2,ind1,ind2-1,dp);
           dp[ind1][ind2]=min(notmatch1,notmatch2);
           dp[ind1][ind2]=min(notmatch3,dp[ind1][ind2]);
        }
        else{
            dp[ind1][ind2]=convert(s1,s2,ind1-1,ind2-1,dp);
        }
        return dp[ind1][ind2];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans=convert(word1,word2,n-1,m-1,dp);
        return ans;
    }
};