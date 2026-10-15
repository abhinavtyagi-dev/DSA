class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for (int i=0;i<n;i++){
            map<int,int>mpp;
            for (int j=i;j<n;j++){
                mpp[nums[j]]++;
                ans+=(mpp.size()*mpp.size());
            }
            
        }
        return ans;
    }
};