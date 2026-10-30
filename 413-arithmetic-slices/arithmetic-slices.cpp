class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int l=0,r=1;
        int n=nums.size();
        int cnt=0;
        while (r<n){
            int diff=nums[r]-nums[r-1];
            mpp[diff]++;
           
            while (mpp.size()>1){
                 mpp[nums[l+1]-nums[l]]--;
                 if (mpp[nums[l+1]-nums[l]]==0){
                    mpp.erase(nums[l+1]-nums[l]);
                 }
                 l++;
            }
            if ((r-l+1>=3)&&mpp.size()==1){
               cnt+=(r-l+1)-2;
            }
            r++;
        }
        return cnt;
    }
};