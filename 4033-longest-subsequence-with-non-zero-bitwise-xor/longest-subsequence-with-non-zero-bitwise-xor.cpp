class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxcnt=0;
        int xor1=0;
        int l=0;
        for (int i=0;i<nums.size();i++){
          xor1=xor1^nums[i];
          l++;
          if (xor1!=0){
            maxcnt=max(maxcnt,l);
          }
        }
        return maxcnt;
    }
};