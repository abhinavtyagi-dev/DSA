class Solution {
public:
    int longestSubarray(vector<int>& nums) {
    int l=0,r=0;
    int n=nums.size();
    int maxcnt=INT_MIN;
    
    int cnt0=0;
    while (r<n){
      if (nums[r]==0){
        cnt0++;
      }
      while(cnt0>1){
        if (nums[l]==0){
            cnt0--;
        }
        l++;
      }
      if (cnt0<=1){
        maxcnt=max(maxcnt,r-l);
      }
      r++;

    }
    return maxcnt;
    }
};