class Solution {
    int maxamt=INT_MIN;
    int robber(vector<int>& nums,int i,vector<int>& dp){
          if (dp[i]!=INT_MIN){
            maxamt=max(maxamt,dp[i]);
            return dp[i];
          } 
        for (int j=i-2;j>=0;j--){
            dp[i]=max(dp[i],nums[i]+robber(nums,j,dp));
            maxamt=max(maxamt,dp[i]);
        }
        
        return dp[i];
    }
    int robber1(vector<int>& nums,int i,vector<int>&dp1){
         if (dp1[i]!=INT_MIN){
             maxamt=max(maxamt,dp1[i]);
            return dp1[i];
          } 
        for (int j=i-2;j>=0;j--){
            dp1[i]=max(dp1[i],nums[i]+robber(nums,j,dp1));
            maxamt=max(maxamt,dp1[i]);
        }
        
        return dp1[i];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
         int n=nums.size();
         vector<int> dp(n,INT_MIN);
         dp[0]=nums[0];
         dp[1]=nums[1];
         int ans=robber( nums,n-1,dp);
          vector<int> dp1(n,INT_MIN);
           dp1[0]=nums[0];
         dp1[1]=nums[1];
         int ans2=robber1(nums,n-2,dp1);
        return maxamt;
    }
};