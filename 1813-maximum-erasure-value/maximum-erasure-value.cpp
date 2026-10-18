class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        map<int,int>mpp;
        int maxsum=INT_MIN;
       
        int sum1=0;
        while (r<n){
             mpp[nums[r]]++;
             sum1+=nums[r];
             
             while (mpp.size()<(r-l+1)){
                mpp[nums[l]]--;
                sum1-=nums[l];
                if (mpp[nums[l]]==0){
                    mpp.erase(nums[l]);
                }
                l++;
             }
             r++;
           maxsum=max(maxsum,sum1);
        }
        return maxsum;
    }
};