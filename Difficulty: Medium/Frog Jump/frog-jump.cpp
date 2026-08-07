class Solution {
  public:
   int frog(vector<int>&height,vector<int>&dp,int i){
       if (dp[i]!=-1){
           return dp[i];
       }
       
       return dp[i]=min(abs(height[i]-height[i-1])+frog(height,dp,i-1),abs(height[i]-height[i-2])+frog(height,dp,i-2));
   }
    int minCost(vector<int>& height) {
        int n=height.size();
         vector<int>dp(n,-1);
         dp[0]=0;
         dp[1]=0+abs(height[1]-height[0]);
         
         int i=n-1;
         int ans=frog(height,dp,i);
         return ans;
    }
};