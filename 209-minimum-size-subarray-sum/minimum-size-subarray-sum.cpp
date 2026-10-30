class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        long long sum=0;
        int l=0,r=0;
        int n=nums.size();
        int maxlen=INT_MAX;
        while (r<n){
           sum+=nums[r];
           while (sum>=target){
            if(sum>=target){
              maxlen=min(maxlen,r-l+1);
           }
            sum-=nums[l];
            l++;
           }
         r++;
        }
        if (maxlen==INT_MAX){
            return 0;
        }
        return maxlen;
    }
};