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
        vector<int> dp(3004,0);
          dp[nums[0]]=1;
        if (nums[0]==0){
            dp[nums[0]]=2;
        }
      

        for (int i=1;i<n;i++){
            vector<int>curr(3004,0);
            for (int j=0;j<=2001;j++){
                int same=0,diff=0;
                same=dp[abs(j-nums[i])];
                diff=dp[abs(j+nums[i])];
                curr[j]=same+diff;
            }
            dp=curr;
        }
        return dp[abs(target)];
    }
};