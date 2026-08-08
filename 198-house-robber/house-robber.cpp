class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1){
            return nums[0];
        }
       
        int maxamt=INT_MIN;
        maxamt=max(nums[0],nums[1]);
        vector<int> dp(nums.size(),INT_MIN);
        dp[0]=nums[0];
        dp[1]=nums[1];
        for (int i=2;i<nums.size();i++){
            for (int j=i-2;j>=0;j--){
                dp[i]=max(dp[i],nums[i]+dp[j]);
                maxamt=max(maxamt,dp[i]);
            }
        }
        return maxamt;
    }
};