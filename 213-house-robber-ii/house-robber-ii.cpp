class Solution {
public:
    int rob(vector<int>& nums) {
         if (nums.size()==1){
            return nums[0];
        }
        if (nums.size()==2){
            return max(nums[0],nums[1]);
        }
        int maxamt=INT_MIN;
        int max1=nums[0];
        int max2=nums[1];
        maxamt=max(max1,max2);
        int n=nums.size();
        for (int i=2;i<n-1;i++){
            int currmax=max1+nums[i];
            max1=max(max1,max2);
            max2=max(max2,currmax);
            maxamt=max(maxamt,currmax);

        }
        int max3=nums[1];
        int max4=nums[2];
        int maxamt2=INT_MIN;
        maxamt2=max(max3,max4);
        for (int i=3;i<n;i++){
             int currmax=max3+nums[i];
            max3=max(max3,max4);
            max4=max(max4,currmax);
            maxamt2=max(maxamt2,currmax);
        }
       return max(maxamt,maxamt2);
    }
};