class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int n=nums.size();
         if (nums.size()==1){
            if (nums[0]==target){
            if (nums[0]==0){
                return 2;
            }
            else{
               return 1; 
            }
            }
         }
        vector<vector<int>>dp(n,vector<int>(3004,0));
          dp[0][nums[0]]=1;
        if (nums[0]==0){
            dp[0][nums[0]]=2;
        }
      

        for (int i=1;i<n;i++){
            for (int j=0;j<=2001;j++){
                int same=0,diff=0;
                same=dp[i-1][abs(j-nums[i])];
                diff=dp[i-1][abs(j+nums[i])];
                dp[i][j]=same+diff;
            }
        }
        return dp[n-1][abs(target)];
    }
};