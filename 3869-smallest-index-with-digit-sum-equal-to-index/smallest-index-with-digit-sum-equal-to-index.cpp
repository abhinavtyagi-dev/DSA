class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans=-1;
        for (int i=0;i<nums.size();i++){
            int digit=nums[i];
            int sum=0;
            while (digit!=0){
                sum+=digit%10;
                digit=digit/10;
            }
            if (sum==i){
                ans=i;
                break;
            }
        }
        return ans;
    }
};