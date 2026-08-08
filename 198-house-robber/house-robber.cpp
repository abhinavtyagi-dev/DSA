class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size()==1){
            return nums[0];
        }
        int maxamt=INT_MIN;
        int max1=nums[0];
        int max2=nums[1];
        maxamt=max(max1,max2);
        int n=nums.size();
        for (int i=2;i<n;i++){
            int currmax=max1+nums[i];
            max1=max(max1,max2);
            max2=max(max2,currmax);
            maxamt=max(maxamt,currmax);

        }
        return maxamt;
    }
};