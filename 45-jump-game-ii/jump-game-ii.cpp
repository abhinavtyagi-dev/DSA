class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int l=0,r=0;
       while (r<nums.size()-1){
          int ind=r+1;
          int i=l;
          int maxi=INT_MIN;
          while (i<=r){
            maxi=max(maxi,i+nums[i]);
            i++;
          }
          r=maxi;
          l=ind;
          jumps++;

       }
       return jumps;
    }
};